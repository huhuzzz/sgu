%{
#include <cstdio>
extern int yylineno;
extern yyerror(const char *s);
extern int yylex(void);
%}

%token

tok_183/*_r0*/
tok_187/*_r1*/
tok_191/*_r2*/
tok_195/*_r3*/
tok_199/*_r4*/
tok_203/*_r5*/
tok_207/*_r6*/
tok_211/*_r7*/
tok_215/*_r8*/
tok_219/*_r9*/
tok_223/*_r10*/
tok_228/*_r11*/
tok_233/*_r12*/
tok_238/*_r13*/
tok_243/*_r14*/
tok_248/*_r15*/
tok_144/*_a0*/
tok_148/*_a1*/
tok_152/*_a2*/
tok_156/*_a3*/
tok_160/*_a4*/
tok_164/*_a5*/
tok_168/*_a6*/
tok_172/*_a7*/
tok_261/*_c0*/
tok_265/*_c1*/
tok_269/*_c2*/
tok_273/*_c3*/
tok_285/*_o0*/
tok_289/*_o1*/
tok_293/*_o2*/
tok_297/*_o3*/
tok_309/*_b0*/
tok_313/*_b1*/
tok_317/*_b2*/
tok_321/*_b3*/
tok_332/*_m0*/
tok_336/*_m1*/
tok_340/*_m2*/
tok_344/*_m3*/
tok_706/*mov*/
tok_1066/*,*/
tok_1026/*nop*/
tok_510/*add*/
tok_514/*addu*/
tok_519/*sub*/
tok_523/*mul*/
tok_527/*mulu*/
tok_532/*fmul*/
tok_537/*fcmul*/
tok_543/*cmac*/
tok_548/*mac*/
tok_572/*dadd*/
tok_577/*qadd*/
tok_582/*dsub*/
tok_587/*qsub*/
tok_592/*fdmul*/
tok_598/*fqmul*/
tok_604/*dmac*/
tok_609/*qmac*/
tok_614/*dmax*/
tok_619/*qmax*/
tok_624/*dmin*/
tok_629/*qmin*/
tok_655/*and*/
tok_659/*or*/
tok_662/*xor*/
tok_666/*max*/
tok_670/*min*/
tok_674/*sla*/
tok_678/*slaa*/
tok_683/*srl*/
tok_750/*dabs*/
tok_755/*qabs*/
tok_760/*dsum*/
tok_765/*qsum*/

%type <string> rule_reg_all
%type <string> rule_insn64slot1_mov
%type <string> rule_insn64slot1_nop
%type <string> rule_insn64slot1_others_iterm
%type <string> rule_reg_acc
%type <string> rule_insn64slot1_others
%type <string> rule_insn64slot1

%start rule_insn64slot1

%%

rule_reg_all: tok_183 /*_r0*/	{return (string)"000000";}|
 tok_187 /*_r1*/	{return (string)"000001";}|
 tok_191 /*_r2*/	{return (string)"000010";}|
 tok_195 /*_r3*/	{return (string)"000011";}|
 tok_199 /*_r4*/	{return (string)"000100";}|
 tok_203 /*_r5*/	{return (string)"000101";}|
 tok_207 /*_r6*/	{return (string)"000110";}|
 tok_211 /*_r7*/	{return (string)"000111";}|
 tok_215 /*_r8*/	{return (string)"001000";}|
 tok_219 /*_r9*/	{return (string)"001001";}|
 tok_223 /*_r10*/	{return (string)"001010";}|
 tok_228 /*_r11*/	{return (string)"001011";}|
 tok_233 /*_r12*/	{return (string)"001100";}|
 tok_238 /*_r13*/	{return (string)"001101";}|
 tok_243 /*_r14*/	{return (string)"001110";}|
 tok_248 /*_r15*/	{return (string)"001111";}|
 tok_144 /*_a0*/	{return (string)"010000";}|
 tok_148 /*_a1*/	{return (string)"010001";}|
 tok_152 /*_a2*/	{return (string)"010010";}|
 tok_156 /*_a3*/	{return (string)"010011";}|
 tok_160 /*_a4*/	{return (string)"010100";}|
 tok_164 /*_a5*/	{return (string)"010101";}|
 tok_168 /*_a6*/	{return (string)"010110";}|
 tok_172 /*_a7*/	{return (string)"010111";}|
 tok_261 /*_c0*/	{return (string)"011000";}|
 tok_265 /*_c1*/	{return (string)"011001";}|
 tok_269 /*_c2*/	{return (string)"011010";}|
 tok_273 /*_c3*/	{return (string)"011011";}|
 tok_285 /*_o0*/	{return (string)"011100";}|
 tok_289 /*_o1*/	{return (string)"011101";}|
 tok_293 /*_o2*/	{return (string)"011110";}|
 tok_297 /*_o3*/	{return (string)"011111";}|
 tok_309 /*_b0*/	{return (string)"100000";}|
 tok_313 /*_b1*/	{return (string)"100001";}|
 tok_317 /*_b2*/	{return (string)"100010";}|
 tok_321 /*_b3*/	{return (string)"100011";}|
 tok_332 /*_m0*/	{return (string)"100100";}|
 tok_336 /*_m1*/	{return (string)"100101";}|
 tok_340 /*_m2*/	{return (string)"100110";}|
 tok_344 /*_m3*/	{return (string)"100111";}
;
rule_insn64slot1_mov: tok_706 /*mov*/ rule_reg_all tok_1066 /*,*/ rule_reg_all
{ $$ = (string)"100010"+ $2+ $4}
;
rule_insn64slot1_nop: tok_1026 /*nop*/
{ $$ = (string)"000000000000000000"}
;
rule_insn64slot1_others_iterm: tok_510 /*add*/	{return (string)"000001";}|
 tok_514 /*addu*/	{return (string)"000010";}|
 tok_519 /*sub*/	{return (string)"000011";}|
 tok_523 /*mul*/	{return (string)"000100";}|
 tok_527 /*mulu*/	{return (string)"000101";}|
 tok_532 /*fmul*/	{return (string)"000110";}|
 tok_537 /*fcmul*/	{return (string)"000111";}|
 tok_543 /*cmac*/	{return (string)"001000";}|
 tok_548 /*mac*/	{return (string)"001001";}|
 tok_572 /*dadd*/	{return (string)"001010";}|
 tok_577 /*qadd*/	{return (string)"001011";}|
 tok_582 /*dsub*/	{return (string)"001100";}|
 tok_587 /*qsub*/	{return (string)"001101";}|
 tok_592 /*fdmul*/	{return (string)"001110";}|
 tok_598 /*fqmul*/	{return (string)"001111";}|
 tok_604 /*dmac*/	{return (string)"010000";}|
 tok_609 /*qmac*/	{return (string)"010001";}|
 tok_614 /*dmax*/	{return (string)"010010";}|
 tok_619 /*qmax*/	{return (string)"010011";}|
 tok_624 /*dmin*/	{return (string)"010100";}|
 tok_629 /*qmin*/	{return (string)"010101";}|
 tok_655 /*and*/	{return (string)"010110";}|
 tok_659 /*or*/	{return (string)"010111";}|
 tok_662 /*xor*/	{return (string)"011000";}|
 tok_666 /*max*/	{return (string)"011001";}|
 tok_670 /*min*/	{return (string)"011010";}|
 tok_674 /*sla*/	{return (string)"011011";}|
 tok_678 /*slaa*/	{return (string)"011100";}|
 tok_683 /*srl*/	{return (string)"011101";}|
 tok_750 /*dabs*/	{return (string)"011110";}|
 tok_755 /*qabs*/	{return (string)"011111";}|
 tok_760 /*dsum*/	{return (string)"100000";}|
 tok_765 /*qsum*/	{return (string)"100001";}
;
rule_reg_acc: tok_261 /*_c0*/	{return (string)"00";}|
 tok_265 /*_c1*/	{return (string)"01";}|
 tok_269 /*_c2*/	{return (string)"10";}|
 tok_273 /*_c3*/	{return (string)"11";}
;
rule_insn64slot1_others: rule_insn64slot1_others_iterm rule_reg_acc tok_1066 /*,*/ rule_reg_all tok_1066 /*,*/ rule_reg_all
{ $$ = $1+ $2+ $4+ $6}
;
rule_insn64slot1: rule_insn64slot1_mov{$$= $1;}|
 rule_insn64slot1_others{$$= $1;}|
 rule_insn64slot1_nop{$$= $1;}
;