/* C code for program stopTest, generated by snc from ../stop.st */
#include <string.h>
#include <stddef.h>
#include <stdio.h>
#include <limits.h>

#include "seq_snc.h"
# line 9 "../stop.st"
#include <stdlib.h>
# line 10 "../stop.st"
#include "../testSupport.h"

/* Variable declarations */


/* Function declarations */

#define seqg_var (*(struct seqg_vars *const *)seqg_env)

/* Program init func */
static void seqg_init(PROG_ID seqg_env)
{
}

/* Program entry func */
static void seqg_entry(SS_ID seqg_env)
{
# line 13 "../stop.st"
	seq_test_init(1);
}

/****** Code for state "start" in state set "main" ******/

/* Event function for state "start" in state set "main" */
static seqBool seqg_event_main_0_start(SS_ID seqg_env, int *seqg_ptrn, int *seqg_pnst)
{
# line 18 "../stop.st"
	if (seq_delay(seqg_env, 0.5))
	{
		*seqg_pnst = 1;
		*seqg_ptrn = 0;
		return TRUE;
	}
	return FALSE;
}

/* Action function for state "start" in state set "main" */
static void seqg_action_main_0_start(SS_ID seqg_env, int seqg_trn, int *seqg_pnst)
{
	switch(seqg_trn)
	{
	case 0:
		{
# line 19 "../stop.st"
			seqStop(epicsThreadGetIdSelf());
		}
		return;
	}
}

/****** Code for state "final" in state set "main" ******/

/* Event function for state "final" in state set "main" */
static seqBool seqg_event_main_0_final(SS_ID seqg_env, int *seqg_ptrn, int *seqg_pnst)
{
# line 23 "../stop.st"
	if (FALSE)
	{
		*seqg_pnst = 1;
		*seqg_ptrn = 0;
		return TRUE;
	}
	return FALSE;
}

/* Action function for state "final" in state set "main" */
static void seqg_action_main_0_final(SS_ID seqg_env, int seqg_trn, int *seqg_pnst)
{
	switch(seqg_trn)
	{
	case 0:
		{
		}
		return;
	}
}

/****** Code for state "running" in state set "progress" ******/

/* Event function for state "running" in state set "progress" */
static seqBool seqg_event_progress_1_running(SS_ID seqg_env, int *seqg_ptrn, int *seqg_pnst)
{
# line 30 "../stop.st"
	if (seq_delay(seqg_env, 1))
	{
		*seqg_pnst = 0;
		*seqg_ptrn = 0;
		return TRUE;
	}
	return FALSE;
}

/* Action function for state "running" in state set "progress" */
static void seqg_action_progress_1_running(SS_ID seqg_env, int seqg_trn, int *seqg_pnst)
{
	switch(seqg_trn)
	{
	case 0:
		{
# line 31 "../stop.st"
			testFail("still running...\n");
# line 32 "../stop.st"
			seq_test_done();
# line 33 "../stop.st"
			exit(0);
		}
		return;
	}
}

/* Program exit func */
static void seqg_exit(SS_ID seqg_env)
{
# line 39 "../stop.st"
	testPass("program terminated");
# line 40 "../stop.st"
	seq_test_done();
}

#undef seqg_var

/************************ Tables ************************/

/* No channel definitions */
#define seqg_chans 0

/* Event masks for state set "main" */
static const seqMask seqg_mask_main_0_start[] = {
	0x00000000,
};
static const seqMask seqg_mask_main_0_final[] = {
	0x00000000,
};

/* State table for state set "main" */
static seqState seqg_states_main[] = {
	{
	/* state name */        "start",
	/* action function */   seqg_action_main_0_start,
	/* event function */    seqg_event_main_0_start,
	/* entry function */    0,
	/* exit function */     0,
	/* event mask array */  seqg_mask_main_0_start,
	/* state options */     (0)
	},
	{
	/* state name */        "final",
	/* action function */   seqg_action_main_0_final,
	/* event function */    seqg_event_main_0_final,
	/* entry function */    0,
	/* exit function */     0,
	/* event mask array */  seqg_mask_main_0_final,
	/* state options */     (0)
	},
};

/* Event masks for state set "progress" */
static const seqMask seqg_mask_progress_1_running[] = {
	0x00000000,
};

/* State table for state set "progress" */
static seqState seqg_states_progress[] = {
	{
	/* state name */        "running",
	/* action function */   seqg_action_progress_1_running,
	/* event function */    seqg_event_progress_1_running,
	/* entry function */    0,
	/* exit function */     0,
	/* event mask array */  seqg_mask_progress_1_running,
	/* state options */     (0)
	},
};

/* State set table */
static seqSS seqg_statesets[] = {
	{
	/* state set name */    "main",
	/* states */            seqg_states_main,
	/* number of states */  2
	},

	{
	/* state set name */    "progress",
	/* states */            seqg_states_progress,
	/* number of states */  1
	},
};

/* Program table (global) */
seqProgram stopTest = {
	/* magic number */      2002006,
	/* program name */      "stopTest",
	/* channels */          seqg_chans,
	/* num. channels */     0,
	/* state sets */        seqg_statesets,
	/* num. state sets */   2,
	/* user var size */     0,
	/* param */             "",
	/* num. event flags */  0,
	/* encoded options */   (0 | OPT_CONN | OPT_NEWEF),
	/* init func */         seqg_init,
	/* entry func */        seqg_entry,
	/* exit func */         seqg_exit,
	/* num. queues */       0
};

#define PROG_NAME stopTest
#include "seqMain.c"

/* Register sequencer commands and program */
#include "epicsExport.h"
static void stopTestRegistrar (void) {
    seqRegisterSequencerCommands();
    seqRegisterSequencerProgram (&stopTest);
}
epicsExportRegistrar(stopTestRegistrar);
