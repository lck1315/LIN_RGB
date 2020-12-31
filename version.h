#ifndef _VERSION_H_
#define _VERSION_H_

// Numbering suggestion:
// 
// ++Major: Redesign / Major changes
// ++Minor: Backward incompatible API changes
// ++Build:	Any change, small/internal bugfixes etc.

#define MAIN_VERSION_MAJOR		1
#define MAIN_VERSION_MAJOR_STR	        "1" 
 
#define MAIN_VERSION_MINOR		0
#define MAIN_VERSION_MINOR_STR	        "0"

#define MAIN_VERSION_BUILD		2
#define MAIN_VERSION_BUILD_STR	        "2"

#define MAIN_VERSION_PROJECT            "LEDDemo"
#define MAIN_VERSION_AUTHOR             "ELMOS Semiconductor AG"

#define MAIN_VERSION_YEAR               "2013"

#define MAIN_VERSION_
#define MAIN_VERSION_NUMBER			((MAIN_VERSION_MAJOR<<24)|(MAIN_VERSION_MINOR<<16)|MAIN_VERSION_BUILD) // Bit: 31-24 Major, 23-16 Minor, 15-0 Build
#define MAIN_VERSION_STRING			"v"  MAIN_VERSION_MAJOR_STR "." MAIN_VERSION_MINOR_STR "." MAIN_VERSION_BUILD_STR
#define MAIN_VERSION_STRING_LONG		MAIN_VERSION_PROJECT " " MAIN_VERSION_STRING " (c)" MAIN_VERSION_YEAR " " MAIN_VERSION_AUTHOR

/* --------------------------------------------------------------------------------------------------------------- *
 * Date      Version    Who   Comment
 * YY/MM/DD  Ma.Mi.Bd
 * --------------------------------------------------------------------------------------------------------------- *
 * 13/10/16  1.0.2      RPY   Update ADC sampling time.
 * 13/09/02  1.0.1      RPY   Initial version taken from 521.31GPDemo v1.0.6
 * --------------------------------------------------------------------------------------------------------------- */

#endif