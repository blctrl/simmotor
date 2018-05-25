/* Generated file epicsVersion.h */

#ifndef INC_epicsVersion_H
#define INC_epicsVersion_H

#define EPICS_VERSION        3
#define EPICS_REVISION       16
#define EPICS_MODIFICATION   1
#define EPICS_PATCH_LEVEL    0
#define EPICS_DEV_SNAPSHOT   ""
#define EPICS_SITE_VERSION   ""

#define EPICS_VERSION_SHORT  "3.16.1"
#define EPICS_VERSION_FULL   "3.16.1"
#define EPICS_VERSION_STRING "EPICS 3.16.1"
#define epicsReleaseVersion  "EPICS R3.16.1"

#ifndef VERSION_INT
#  define VERSION_INT(V,R,M,P) ( ((V)<<24) | ((R)<<16) | ((M)<<8) | (P))
#endif
#define EPICS_VERSION_INT VERSION_INT(3, 16, 1, 0)

#endif /* INC_epicsVersion_H */
