/* C code for program opttTest, generated by snc from ../optt.st */
#include <string.h>
#include <stddef.h>
#include <stdio.h>
#include <limits.h>

#include "seq_snc.h"
# line 9 "../optt.st"
#include "epicsThread.h"

/* Variable declarations */
# line 11 "../optt.st"
static	float v;


/* Function declarations */

#define seqg_var (*(struct seqg_vars *const *)seqg_env)

/* Program init func */
static void seqg_init(PROG_ID seqg_env)
{
}

/****** Code for state "low" in state set "ss1" ******/

/* Entry function for state "low" in state set "ss1" */
static void seqg_entry_ss1_0_low(SS_ID seqg_env)
{
# line 22 "../optt.st"
	printf("Print something on entry to low\n");
# line 23 "../optt.st"
	printf("Also pause on entry to low\n");
# line 24 "../optt.st"
	epicsThreadSleep(1.0);
}

/* Exit function for state "low" in state set "ss1" */
static void seqg_exit_ss1_0_low(SS_ID seqg_env)
{
# line 38 "../optt.st"
	printf("low, print this on exit of low\n");
}

/* Event function for state "low" in state set "ss1" */
static seqBool seqg_event_ss1_0_low(SS_ID seqg_env, int *seqg_ptrn, int *seqg_pnst)
{
# line 26 "../optt.st"
	if (v > 5.0)
	{
		*seqg_pnst = 1;
		*seqg_ptrn = 0;
		return TRUE;
	}
# line 30 "../optt.st"
	if (seq_delay(seqg_env, 2.0))
	{
		*seqg_pnst = 0;
		*seqg_ptrn = 1;
		return TRUE;
	}
	return FALSE;
}

/* Action function for state "low" in state set "ss1" */
static void seqg_action_ss1_0_low(SS_ID seqg_env, int seqg_trn, int *seqg_pnst)
{
	switch(seqg_trn)
	{
	case 0:
		{
# line 28 "../optt.st"
			printf("low, v = %g, now changing to high\n", v);
		}
		return;
	case 1:
		{
# line 32 "../optt.st"
			printf("low, delay timeout, incr v and now reenter low\n");
# line 33 "../optt.st"
			v = v + 1.0;
# line 34 "../optt.st"
			printf("v = %g\n", v);
		}
		return;
	}
}

/****** Code for state "high" in state set "ss1" ******/

/* Entry function for state "high" in state set "ss1" */
static void seqg_entry_ss1_0_high(SS_ID seqg_env)
{
# line 45 "../optt.st"
	printf("\nEntered high\n");
}

/* Event function for state "high" in state set "ss1" */
static seqBool seqg_event_ss1_0_high(SS_ID seqg_env, int *seqg_ptrn, int *seqg_pnst)
{
# line 46 "../optt.st"
	if (v == 0)
	{
		*seqg_pnst = 0;
		*seqg_ptrn = 0;
		return TRUE;
	}
# line 50 "../optt.st"
	if (seq_delay(seqg_env, 3.0))
	{
		*seqg_pnst = 1;
		*seqg_ptrn = 1;
		return TRUE;
	}
	return FALSE;
}

/* Action function for state "high" in state set "ss1" */
static void seqg_action_ss1_0_high(SS_ID seqg_env, int seqg_trn, int *seqg_pnst)
{
	switch(seqg_trn)
	{
	case 0:
		{
# line 48 "../optt.st"
			printf("changing to low\n");
		}
		return;
	case 1:
		{
# line 52 "../optt.st"
			printf("high, delay 3.0 timeout, decr v and re-enter high\n");
# line 53 "../optt.st"
			v = v - 1.0;
# line 54 "../optt.st"
			printf("v = %g\n", v);
		}
		return;
	}
}

#undef seqg_var

/************************ Tables ************************/

/* No channel definitions */
#define seqg_chans 0

/* Event masks for state set "ss1" */
static const seqMask seqg_mask_ss1_0_low[] = {
	0x00000000,
};
static const seqMask seqg_mask_ss1_0_high[] = {
	0x00000000,
};

/* State table for state set "ss1" */
static seqState seqg_states_ss1[] = {
	{
	/* state name */        "low",
	/* action function */   seqg_action_ss1_0_low,
	/* event function */    seqg_event_ss1_0_low,
	/* entry function */    seqg_entry_ss1_0_low,
	/* exit function */     seqg_exit_ss1_0_low,
	/* event mask array */  seqg_mask_ss1_0_low,
	/* state options */     (0 | OPT_NORESETTIMERS)
	},
	{
	/* state name */        "high",
	/* action function */   seqg_action_ss1_0_high,
	/* event function */    seqg_event_ss1_0_high,
	/* entry function */    seqg_entry_ss1_0_high,
	/* exit function */     0,
	/* event mask array */  seqg_mask_ss1_0_high,
	/* state options */     (0)
	},
};

/* State set table */
static seqSS seqg_statesets[] = {
	{
	/* state set name */    "ss1",
	/* states */            seqg_states_ss1,
	/* number of states */  2
	},
};

/* Program table (global) */
seqProgram opttTest = {
	/* magic number */      2002006,
	/* program name */      "opttTest",
	/* channels */          seqg_chans,
	/* num. channels */     0,
	/* state sets */        seqg_statesets,
	/* num. state sets */   1,
	/* user var size */     0,
	/* param */             "",
	/* num. event flags */  0,
	/* encoded options */   (0 | OPT_CONN | OPT_NEWEF),
	/* init func */         seqg_init,
	/* entry func */        0,
	/* exit func */         0,
	/* num. queues */       0
};

#define PROG_NAME opttTest
#include "seqMain.c"

/* Register sequencer commands and program */
#include "epicsExport.h"
static void opttTestRegistrar (void) {
    seqRegisterSequencerCommands();
    seqRegisterSequencerProgram (&opttTest);
}
epicsExportRegistrar(opttTestRegistrar);
