/*  ------------------------------------------------------
     Routine name:  my_diagram
     Description:   
     Project file:  Задержка автомат.prt

------------------------------------------------------  */

/*       Local stack variables                */
int i;
int j;
int c;
int itmp1;
int itmp2;
int itmp3;
double tmp1;
double tmp2;
double tmp3;
double tmp4;
double tmp5;
double tmp6;
double tmp7;
char f;
char tmp_f_1;
char u_s;
char u_r;
symbol = (enum DelayInputSymbol)state_vars->my_diagramv0_out_0_;
output = delay_engine(&engine, symbol);
state_vars->my_diagramv1_out_0_ = output;
ret = 0;

switch (action){
case f_Stop:{
};break;
case f_GetDeri:{
};break;
case f_GetAlgFun:{
};break;
default:{

/* Index=0
   UID=0
   GeneratorClassName=TInputPin
   Name=Const_source19
   Type=Входной контакт */

state_vars->my_diagramv0_out_0_ = ((input_0));

/* Index=2
   UID=2
   GeneratorClassName=TOutPin
   Name=OutPin16
   Type=Выходной контакт */

if(isfinite(state_vars->my_diagramv1_out_0_)){
out_0 = state_vars->my_diagramv1_out_0_;
};
};break;
};
