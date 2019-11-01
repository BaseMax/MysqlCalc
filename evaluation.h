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
		TE_VARIABLE = 0,

		TE_FUNCTION0 = 8, TE_FUNCTION1, TE_FUNCTION2, TE_FUNCTION3,
		TE_FUNCTION4, TE_FUNCTION5, TE_FUNCTION6, TE_FUNCTION7,

		TE_CLOSURE0 = 16, TE_CLOSURE1, TE_CLOSURE2, TE_CLOSURE3,
		TE_CLOSURE4, TE_CLOSURE5, TE_CLOSURE6, TE_CLOSURE7,

		TE_FLAG_PURE = 32
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
