#ifndef __MCALC_H__
	#define __MCALC_H__
	
	#ifdef __cplusplus
	extern "C" {
	#endif

	typedef struct mcalc_expr {
		int type;
		union {double value; const double *bound; const void *function;};
		void *parameters[1];
	} mcalc_expr;

	enum {
		MCALC_VARIABLE = 0,

		MCALC_FUNCTION0 = 8, MCALC_FUNCTION1, MCALC_FUNCTION2, MCALC_FUNCTION3,
		MCALC_FUNCTION4, MCALC_FUNCTION5, MCALC_FUNCTION6, MCALC_FUNCTION7,

		MCALC_CLOSURE0 = 16, MCALC_CLOSURE1, MCALC_CLOSURE2, MCALC_CLOSURE3,
		MCALC_CLOSURE4, MCALC_CLOSURE5, MCALC_CLOSURE6, MCALC_CLOSURE7,

		MCALC_FLAG_PURE = 32
	};

	typedef struct mcalc_variable {
		const char *name;
		const void *address;
		int type;
		void *context;
	} mcalc_variable;

	double mcalc_interp(const char *expression, int *error);
	mcalc_expr *mcalc_compile(const char *expression, const mcalc_variable *variables, int var_count, int *error);
	double mcalc_eval(const mcalc_expr *n);
	void mcalc_print(const mcalc_expr *n);
	void mcalc_free(mcalc_expr *n);

	#ifdef __cplusplus
	}
	#endif
#endif
