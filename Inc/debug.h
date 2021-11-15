#ifndef __DEBUG_H
#define __DEBUG_H


#ifdef __cplusplus
extern "C" {
#endif

	
#define DEBUG

#ifdef DEBUG
#define PRINTF(...) printf(__VA_ARGS__)
#else
#define PRINTF(...)
#endif
	
	

#ifdef __cplusplus
}
#endif

#endif /* __DEBUG_H */
