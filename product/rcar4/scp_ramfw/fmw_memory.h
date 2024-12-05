/*
* LICENSE ...
*/

#ifndef FMW_MEMORY_H
#define FMW_MEMORY_H

#include <system_mmap_scp.h>  // "" oder <> ??

#define FMW_MEM_MODE ARCH_MEM_MODE_SINGLE_REGION

/*
* RAM memory
*/
#define FWM_MEM0_SIZE SCP_RAM_SIZE
#define FWM_MEM0_BASE SCP_RAM_BASE

#define FWM_STACK_SIZE (***)

#endif /* FMW_MEMORY_H */

