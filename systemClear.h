/* Directives to allow the "clear" command to be portable across 
 * different operating systems */ 


#if defined(_WIN32) || defined(_WIN64)
	const char * clearCommand = "cls"; 
#elif defined (__linux__) || defined (__APPLE__) || defined (__UNIX__)
	const char * clearCommand = "clear";
#else
	const char * clearCommand = NULL;
#endif
