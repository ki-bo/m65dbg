/* vim: set expandtab shiftwidth=2 tabstop=2: */

#include <stdbool.h>

void listSearch(void);
void cmdRawHelp(void);
void cmdHelp(void);
void cmdDump(void);
void cmdMDump(void);
void cmdAssemble(void);
void cmdDisassemble(void);
void cmdMDisassemble(void);
void cmdSoftContinue(void);
void cmdContinue(void);
bool cmdGetContinueMode(void);
void cmdSetContinueMode(bool val);
void cmdStep(void);
void cmdHardNext(void);
void cmdNext(void);
void cmdFinish(void);
void cmdPrintByte(void);
void cmdPrintWord(void);
void cmdPrintDWord(void);
void cmdPrintQWord(void);
void cmdPrintString(void);
void cmdPrintMByte(void);
void cmdPrintMWord(void);
void cmdPrintMDWord(void);
void cmdPrintMQWord(void);
void cmdPrintMString(void);
void cmdClearScreen(void);
void cmdAutoClearScreen(void);
void cmdSetBreakpoint(void);
void cmdSetSoftwareBreakpoint(void);
void cmdWatchByte(void);
void cmdWatchWord(void);
void cmdWatchDWord(void);
void cmdWatchQWord(void);
void cmdWatchString(void);
void cmdWatchDump(void);
void cmdWatchMByte(void);
void cmdWatchMWord(void);
void cmdWatchMDWord(void);
void cmdWatchMQWord(void);
void cmdWatchMString(void);
void cmdWatchMDump(void);
void cmdWatches(void);
void cmdDeleteWatch(void);
void cmdAutoWatch(void);
void cmdSymbolValue(void);
void cmdSave(void);
void cmdLoad(void);
void cmdMPoke(void);
void cmdMPokeW(void);
void cmdMPokeD(void);
void cmdMPokeQ(void);
void cmdBackTrace(void);
void cmdUpFrame(void);
void cmdDownFrame(void);
void cmdSearch(void);
void cmdScreenshot(void);
void cmdType(void);
void cmdFtp(void);
void cmdPetscii(void);
void cmdFastMode(void);
void cmdScope(void);
void cmdOffs(void);
void cmdPrintValue(void);
void cmdForwardDis(void);
void cmdBackwardDis(void);
void cmdMCopy(void);
void cmdLocals(void);
void cmdAutoLocals(void);
void cmdMapping(void);
int doOneShotAssembly(char* strCommand);
int  cmdGetCmdCount(void);
char* cmdGetCmdName(int idx);
int isValidMnemonic(char* str);

#define BUFSIZE 4096

extern char outbuf[];
extern char inbuf[];
extern bool ctrlcflag;

typedef struct
{
  char* name;
  void (*func)(void);
  char* params;
  char* help;
} type_command_details;

typedef struct tse
{
  char* symbol;
  int addr;   // integer value of symbol
  char* sval; // string value of symbol
  struct tse* next;
} type_symmap_entry;

typedef struct tseg
{
  char name[64];
  int offset;
} type_segment;

typedef struct t_o
{
  char modulename[256];
  type_segment segments[32];
  int seg_cnt;
  int enabled;
  struct t_o* next;
} type_offsets;

typedef enum { TYPE_BYTE, TYPE_WORD, TYPE_DWORD, TYPE_QWORD, TYPE_STRING, TYPE_DUMP,
    TYPE_MBYTE, TYPE_MWORD, TYPE_MDWORD, TYPE_MQWORD, TYPE_MSTRING, TYPE_MDUMP } type_watch;
extern char* type_names[];

typedef struct we
{
  type_watch type;
  bool show_decimal;
  char* name;
  char* param1;
  struct we* next;
} type_watch_entry;

extern type_command_details command_details[];
extern type_symmap_entry* lstSymMap;
extern type_watch_entry* lstWatches;
