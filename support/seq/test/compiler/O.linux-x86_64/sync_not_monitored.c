/* C code for program p, generated by snc from ../sync_not_monitored.st */
#include <string.h>
#include <stddef.h>
#include <stdio.h>
#include <limits.h>

#include "seq_snc.h"
# line 11 "../sync_not_monitored.st"
static const EF_ID f = 1;

/* Variable declarations */
# line 9 "../sync_not_monitored.st"
static	float x;


/* Function declarations */

#define seqg_var (*(struct seqg_vars *const *)seqg_env)

/* Program init func */
static void seqg_init(PROG_ID seqg_env)
{
	{
# line 9 "../sync_not_monitored.st"
	static float seqg_initvar_x = 0.0;
	memcpy(&x, &seqg_initvar_x, sizeof(seqg_initvar_x));
	}
}

/****** Code for state "simple" in state set "simple" ******/

/* Event function for state "simple" in state set "simple" */
static seqBool seqg_event_simple_0_simple(SS_ID seqg_env, int *seqg_ptrn, int *seqg_pnst)
{
# line 17 "../sync_not_monitored.st"
	if (x == x)
	{
		seq_exit(seqg_env);
		*seqg_ptrn = 0;
		return TRUE;
	}
	return FALSE;
}

/* Action function for state "simple" in state set "simple" */
static void seqg_action_simple_0_simple(SS_ID seqg_env, int seqg_trn, int *seqg_pnst)
{
	switch(seqg_trn)
	{
	case 0:
		{
# line 18 "../sync_not_monitored.st"
			seq_efSet(seqg_env, f);
		}
		return;
	}
}

#undef seqg_var

/************************ Tables ************************/

/* Channel table */
static seqChan seqg_chans[] = {
	/* chName, offset, varName, varType, count, eventNum, efId, monitored, queueSize, queueIndex */
	{"", (size_t)&x, "x", P_FLOAT, 1, 2, 1, 0, 0, 0},
};

/* Event masks for state set "simple" */
static const seqMask seqg_mask_simple_0_simple[] = {
	0x00000004,
};

/* State table for state set "simple" */
static seqState seqg_states_simple[] = {
	{
	/* state name */        "simple",
	/* action function */   seqg_action_simple_0_simple,
	/* event function */    seqg_event_simple_0_simple,
	/* entry function */    0,
	/* exit function */     0,
	/* event mask array */  seqg_mask_simple_0_simple,
	/* state options */     (0)
	},
};

/* State set table */
static seqSS seqg_statesets[] = {
	{
	/* state set name */    "simple",
	/* states */            seqg_states_simple,
	/* number of states */  1
	},
};

/* Program table (global) */
seqProgram p = {
	/* magic number */      2002006,
	/* program name */      "p",
	/* channels */          seqg_chans,
	/* num. channels */     1,
	/* state sets */        seqg_statesets,
	/* num. state sets */   1,
	/* user var size */     0,
	/* param */             "",
	/* num. event flags */  1,
	/* encoded options */   (0 | OPT_CONN | OPT_NEWEF),
	/* init func */         seqg_init,
	/* entry func */        0,
	/* exit func */         0,
	/* num. queues */       0
};

#define PROG_NAME p
#include "seqMain.c"

/* Register sequencer commands and program */
#include "epicsExport.h"
static void pRegistrar (void) {
    seqRegisterSequencerCommands();
    seqRegisterSequencerProgram (&p);
}
epicsExportRegistrar(pRegistrar);