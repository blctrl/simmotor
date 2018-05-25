#!../../bin/linux-x86_64/sm

#- You may have to change sm to something else
#- everywhere it appears in this file

< envPaths

cd "${TOP}"

## Register all support components
dbLoadDatabase "dbd/sm.dbd"
sm_registerRecordDeviceDriver pdbbase

## Load record instances
#dbLoadRecords("db/xxx.db","user=blctrl")
dbLoadRecords("db/xxx.db","user=blctrl")

dbLoadTemplate("iocBoot/iocsm/motor.substitutions")
motorSimCreateController("sm", 8)

# motorSimConfigAxis(port, axis, lowLimit, highLimit, home, start)
motorSimConfigAxis("sm", 0, 20000, -20000,  500, 0)
motorSimConfigAxis("sm", 1, 20000, -20000, 1500, 0)
motorSimConfigAxis("sm", 2, 20000, -20000, 2500, 0)
motorSimConfigAxis("sm", 3, 20000, -20000, 3000, 0)
motorSimConfigAxis("sm", 4, 20000, -20000,  500, 0)
motorSimConfigAxis("sm", 5, 20000, -20000, 1500, 0)
motorSimConfigAxis("sm", 6, 20000, -20000, 2500, 0)
motorSimConfigAxis("sm", 7, 20000, -20000, 3000, 0)



cd "${TOP}/iocBoot/${IOC}"
iocInit

## Start any sequence programs
#seq sncxxx,"user=blctrl"
