/* C code for program structdefTest, generated by snc from ../structdef.st */
#include <string.h>
#include <stddef.h>
#include <stdio.h>
#include <limits.h>

#include "seq_snc.h"
# line 3 "../structdef.st"
#include "../testSupport.h"
# line 7 "../structdef.st"
#include <stdlib.h>

struct limits {
# line 10 "../structdef.st"
	double low;
# line 11 "../structdef.st"
	double high;
};

struct mystruct {
# line 15 "../structdef.st"
	char *name;
# line 16 "../structdef.st"
	double value[5];
# line 17 "../structdef.st"
	struct limits warning;
# line 18 "../structdef.st"
	struct limits alarm;
# line 19 "../structdef.st"
	double deadband;
# line 20 "../structdef.st"
	void (*process)(struct mystruct *ps);
# line 21 "../structdef.st"
	struct mystruct *children[2];
# line 22 "../structdef.st"
	int mark;
};
# line 25 "../structdef.st"

void test_array(double *v, double *w, int n);
void test_mystruct(struct mystruct *p);


/* Variable declarations */
# line 30 "../structdef.st"
static	struct mystruct s;


/* Function declarations */

#define seqg_var (*(struct seqg_vars *const *)seqg_env)

/* Program init func */
static void seqg_init(PROG_ID seqg_env)
{
	{
# line 30 "../structdef.st"
	static struct mystruct seqg_initvar_s = {"xxx", {0.0, 1.1, 2.2, 3.3, 4.4}, {-8, +8}, {-10, +10}, 0.01, test_mystruct, {&s, &s}, 0};
	memcpy(&s, &seqg_initvar_s, sizeof(seqg_initvar_s));
	}
}

/* Program entry func */
static void seqg_entry(SS_ID seqg_env)
{
# line 33 "../structdef.st"
	struct mystruct *ps = *(&s.children[0] + 1);
# line 35 "../structdef.st"
	seq_test_init(24);
# line 37 "../structdef.st"
	if (s.process)
# line 38 "../structdef.st"
		s.process(ps);
# line 39 "../structdef.st"
	ps->children[1]->process(ps->children[0]);
}

/****** Code for state "trivial" in state set "trivial" ******/

/* Event function for state "trivial" in state set "trivial" */
static seqBool seqg_event_trivial_0_trivial(SS_ID seqg_env, int *seqg_ptrn, int *seqg_pnst)
{
# line 44 "../structdef.st"
	if (seq_delay(seqg_env, 1))
	{
		seq_exit(seqg_env);
		*seqg_ptrn = 0;
		return TRUE;
	}
	return FALSE;
}

/* Action function for state "trivial" in state set "trivial" */
static void seqg_action_trivial_0_trivial(SS_ID seqg_env, int seqg_trn, int *seqg_pnst)
{
	switch(seqg_trn)
	{
	case 0:
		{
		}
		return;
	}
}

/* Program exit func */
static void seqg_exit(SS_ID seqg_env)
{
# line 49 "../structdef.st"
	seq_test_done();
}

#undef seqg_var

/************************ Tables ************************/

/* No channel definitions */
#define seqg_chans 0

/* Event masks for state set "trivial" */
static const seqMask seqg_mask_trivial_0_trivial[] = {
	0x00000000,
};

/* State table for state set "trivial" */
static seqState seqg_states_trivial[] = {
	{
	/* state name */        "trivial",
	/* action function */   seqg_action_trivial_0_trivial,
	/* event function */    seqg_event_trivial_0_trivial,
	/* entry function */    0,
	/* exit function */     0,
	/* event mask array */  seqg_mask_trivial_0_trivial,
	/* state options */     (0)
	},
};

/* State set table */
static seqSS seqg_statesets[] = {
	{
	/* state set name */    "trivial",
	/* states */            seqg_states_trivial,
	/* number of states */  1
	},
};

/* Program table (global) */
seqProgram structdefTest = {
	/* magic number */      2002006,
	/* program name */      "structdefTest",
	/* channels */          seqg_chans,
	/* num. channels */     0,
	/* state sets */        seqg_statesets,
	/* num. state sets */   1,
	/* user var size */     0,
	/* param */             "",
	/* num. event flags */  0,
	/* encoded options */   (0 | OPT_CONN | OPT_NEWEF),
	/* init func */         seqg_init,
	/* entry func */        seqg_entry,
	/* exit func */         seqg_exit,
	/* num. queues */       0
};
# line 52 "../structdef.st"

void test_array(double *v, double *w, int n) {
    int i;
    for (i=0; i<n; i++) {
        testDiag("v[%d]=%.1f",i,v[i]);
        testDiag("w[%d]=%.1f",i,w[i]);
        testOk1(v[i]==w[i]);
    }
}

void test_mystruct(struct mystruct *p) {
    int i;
    if (p->mark) {
        testDiag("%s already dumped\n", p->name);
    } else {
        p->mark = 1;
        testDiag("name=%s, value=", p->name);
        testOk1(p->name==s.name);
        test_array(p->value, s.value, 5);
        testDiag("  warning={%.1f,%.1f}, alarm={%.1f,%.1f}, deadband=%.1f, process=%p\n",
            p->warning.low, p->warning.high,
            p->alarm.low, p->alarm.high,
            p->deadband, p->process);
        testOk1(p->warning.low==s.warning.low);
        testOk1(p->warning.high==s.warning.high);
        testOk1(p->alarm.low==s.alarm.low);
        testOk1(p->alarm.high==s.alarm.high);
        testOk1(p->deadband==s.deadband);
        testOk1(p->process==s.process);
        for (i=0; i<2; i++) {
            test_mystruct(p->children[i]);
        }
        p->mark = 0;
    }
}


#define PROG_NAME structdefTest
#include "seqMain.c"

/* Register sequencer commands and program */
#include "epicsExport.h"
static void structdefTestRegistrar (void) {
    seqRegisterSequencerCommands();
    seqRegisterSequencerProgram (&structdefTest);
}
epicsExportRegistrar(structdefTestRegistrar);
