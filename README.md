# M-Calc, MCalc

## MCalc Exmaple

```sql
select mcalc('5+5*2/2') as valu;
select mcalc('5+cos(0)') as valu;
select mcalc('5+pi*2)') as valu;
```

# MariaDB-MySQL Calculator 

A MySQL/MariaDB module and plugin to calculate the formula and calculate mathematical expression.

# MariaDB-Mysql UDF

Extend your MySQL server with additional functions

## UDF Plugin-Module for MySQL

### Compiling

```
gcc -shared -o mcalc.so mcalc.cc evaluation.c -std=c++11 -fPIC
cd sql
make mcalc.o
```

### Installing module

```sql
CREATE FUNCTION mcalc RETURNS double SONAME "mcalc.so";
```

### Uninstalling module

```sql
DROP FUNCTION mcalc;
```

# MariaDB-MySQL Calc

### Add module as mysql plugins

It will show path where to put the `.so` file:

```sql
SHOW VARIABLES LIKE 'plugin_dir';
```

**Tested on: MariaDB 10.3.18**

# MariaDB-MySQL References

- https://github.com/BaseMax/FirstMysqlUDF
- https://github.com/MariaDB/server
- https://github.com/mysql/mysql-server
- tinyexpr, c calculator, c expression calc (Lewis Van Winkle)

---------

# Max Base

My nickname is Max, Programming language developer, Full-stack programmer. I love computer scientists, researchers, and compilers.

## Asrez Team

A team includes some programmer, developer, designer, researcher(s) especially Max Base.

[Asrez Team](https://www.asrez.com/)
