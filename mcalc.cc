/**
 *
 * @Name : MysqlCalc
 * @Version : 1.0
 * @Programmer : Max
 * @Date : 2019-11-02
 * @Released under : https://github.com/BaseMax/MysqlCalc/blob/master/LICENSE
 * @Repository : https://github.com/BaseMax/MysqlCalc
 *
**/
/*
** A dynamicly loadable file should be compiled shared.
** (something like: gcc -shared -o my_func.so myfunc.cc).
** You can easily get all switches right by doing:
** cd sql ; make mcalc.o
** Take the compile line that make writes, remove the '-c' near the end of
** the line and add -shared -o mcalc.so to the end of the compile line.
** The resulting library (mcalc.so) should be copied to some dir
** searched by ld. (/usr/lib ?)
** If you are using gcc, then you should be able to create the mcalc.so
** by simply doing 'make mcalc.so'.
**
** After the library is made one must notify mysqld about the new
** functions with the commands:
**
** CREATE FUNCTION mcalc RETURNS STRING SONAME "mcalc.so";
**
** After this the functions will work exactly like native MySQL functions.
** Functions should be created only once.
**
** The functions can be deleted by:
**
** DROP FUNCTION mcalc;
*/

#include <assert.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <algorithm>
#include <mutex>
#include <new>
#include <regex>
#include <string>
#include <vector>

// For MySQL
#include "mysql.h"
// For MariaDB
// #include "mariadb.h"
// #include "mariadb/mysql.h"

// #include "mysql/udf_registration_types.h" Not need.

#ifdef _WIN32
	#pragma comment(lib, "ws2_32")
#endif

extern "C" bool mcalc_init(UDF_INIT *initid, UDF_ARGS *args, char *message) {
	if(args->arg_count != 1 || args->arg_type[0] != STRING_RESULT) {
		strcpy(message, "Wrong arguments to mcalc!");
		return 1;
	}
	return 0;
}

extern "C" void mcalc_deinit(UDF_INIT *) {}

extern "C" double mcalc(UDF_INIT *, UDF_ARGS *args, char *result, unsigned long *length, unsigned char *is_null, unsigned char *) {
	const char *input = args->args[0];
	if (!input) {
		assert(args->lengths[0] == 0);
		*is_null = 1;
		return 0;
	}
	// double r=(double) strlen(input);
	double r = te_interp(input, 0);
	return r;
}
