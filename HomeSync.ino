#include <Stepper.h>

String inputString  = "";
boolean stringComplete = false;
 
 
//DEFINE PINS
int AppleIRledPin = A1;
int tvIRledPin = A2;
int fireplaceIRledPin = A3;
int soundbarIRledPin = A0;

//indicator light
int indicatorPin = 13;

//blinds
int blindsStop = 6; // yellow
int blindsDown = 8; // white
int blindsUp = 7; //blue

//Relays
int porchLight = 4;
int dinningRoomLight = 2;
int livingRoomLight = 11;
int bedroomLight = 3;
int kitchenLight = 9;

//DEFINE ARRAYS FOR SENDING 
//APPLE INFO
//PROGMEM  short appleUpArray[] = {8940,4340,620,480,620,1560,620,1560,620,1560,620,480,620,1560,620,1560,620,1560,620,1560,620,1560,620,1560,620,480,620,480,620,480,600,480,620,1560,620,1560,620,1560,620,480,620,1560,620,480,620,480,620,480,620,480,620,1560,620,1540,640,1540,640,460,620,1560,620,1560,620,480,620,1580,620,35260,8900,2160,620};
//PROGMEM  short appleUpArrayCount = 70;
//
//PROGMEM  short appleLeftArray[] = {8980,4300,640,460,640,1540,620,1560,620,1560,620,480,620,1560,620,1560,620,1560,620,1560,620,1560,620,1560,620,480,620,460,640,460,640,460,620,1560,620,480,620,480,620,480,620,1540,640,460,640,460,620,480,620,480,620,1560,620,1560,620,1560,620,480,620,1560,620,1560,620,460,620,1580,620,37480,8940,2120,620};
//PROGMEM  short appleLeftArrayCount = 70;
//
//PROGMEM  short appleRightArray[] = {8980,4320,620,480,620,1560,620,1540,640,1540,640,460,640,1540,640,1540,640,1540,640,1540,640,1540,640,1540,620,480,620,480,620,460,640,460,640,1540,640,1540,640,1540,640,1540,640,460,620,480,620,480,620,460,640,460,640,1540,640,1540,640,1540,640,460,640,1540,620,1560,620,460,640,1560,640,35240,8960,2120,620};
//PROGMEM  short appleRightArrayCount = 70;
//
//PROGMEM  short appleDownArray[] = {8920,4360,560,540,560,1620,560,1620,560,1620,560,540,560,1620,560,1620,560,1620,560,1620,560,1620,560,1620,560,540,560,520,580,520,580,520,560,1620,560,1620,560,540,560,1620,560,1620,560,540,560,540,560,540,560,520,560,1620,560,1620,560,1620,560,540,560,1620,560,1620,560,540,560,1640,560,35320,8900,2180,560,28904,8920,2140,600};
//PROGMEM  short appleDownArrayCount = 74;
//
//PROGMEM  short appleOkayArray[] = {8920,4380,560,540,560,1620,560,1620,560,1620,560,540,560,1600,580,1620,560,1600,580,1600,580,1600,560,1620,560,540,560,540,560,540,560,540,560,1620,560,1620,560,540,560,1620,560,1620,560,1620,560,520,580,1600,580,520,560,1620,560,1620,560,1620,560,540,560,1620,560,1620,560,540,560,1640,560,33280,8880,4380,600,500,560,1620,600,1580,560,1620,600,500,600,1580,600,1580,600,1580,600,1580,600,1560,620,1560,620,480,620,480,620,480,600,500,600,1580,600,500,600,500,600,1580,600,480,620,480,620,480,620,480,600,500,600,1580,600,1580,600,1580,600,500,600,1580,600,1580,600,480,620,1580,620};
//PROGMEM  short appleOkayArrayCount = 134;
//
//PROGMEM  short appleMenuArray[] = {8980,4300,640,460,620,1560,620,1560,620,1560,620,480,620,1560,620,1560,620,1560,620,1560,620,1560,620,1560,620,480,620,460,620,480,620,480,620,1560,620,480,620,1560,620,480,620,480,620,460,620,480,620,480,620,480,620,1560,620,1560,620,1560,620,480,620,1560,620,1560,620,460,620,1580,620,37480,8940,2140,620};
//PROGMEM  short appleMenuArrayCount = 70;
//
//PROGMEM  short applePausePlayArray[] = {8960,4320,620,480,620,1540,640,1540,640,1540,620,480,620,1560,620,1560,620,1560,620,1560,620,1560,620,1560,620,480,620,480,620,460,620,480,620,1560,620,480,620,1560,620,1560,620,1560,620,1560,620,460,640,1540,640,460,620,1560,620,1560,620,1560,620,480,620,1560,620,1540,640,460,620,1580,620,33220,8940,4320,620,480,620,1560,620,1560,620,1540,640,460,620,1560,620,1560,620,1560,600,1580,580,1600,580,1600,560,520,580,520,580,520,560,540,560,1620,560,540,560,540,560,1600,580,520,580,520,560,540,560,540,560,540,560,1620,560,1620,560,1600,580,520,560,1620,560,1620,560,540,560,1640,560,37480,8960,2180,580};
//PROGMEM  short applePausePlayArrayCount = 138;
//
////TV INFO
//PROGMEM  short tvPowerArray[] = {8940,4360,640,480,620,480,660,460,640,1580,640,460,640,480,620,480,640,480,640,1580,620,1600,620,1600,620,480,660,1560,660,1560,620,1600,620,1600,620,1600,620,500,620,1600,620,480,640,480,620,480,640,480,620,480,620,500,640,1580,620,480,620,1600,620,1600,620,1600,620,1600,620,1600,620,39000,8940,2160,620};
//PROGMEM  short tvPowerArrayCount = 70;
//
//PROGMEM  short tvVolumeUpArray[] = {8880,4420,560,540,580,540,560,560,560,1660,560,540,560,540,580,540,560,540,580,1640,560,1660,560,1660,600,520,560,1660,560,1660,580,1640,580,1640,560,1640,580,540,560,560,560,540,560,560,560,540,560,1660,560,560,560,540,560,1660,560,1660,580,1640,580,1640,580,1640,560,540,580,1640,580,39060,8880,2200,620};
//PROGMEM  short tvVolumeUpArrayCount = 70;
//
//PROGMEM  short tvVolumeDownArray[] = {8920,4380,580,520,600,520,580,520,600,1620,600,520,580,520,600,520,580,520,600,1620,600,1620,600,1620,600,520,580,1640,580,1640,580,1620,600,1620,600,520,600,520,580,520,600,520,580,520,600,520,580,520,600,500,600,1620,600,1620,600,1620,600,1640,580,1620,600,1620,600,1620,600,1620,600,39020,8940,2160,580};
//PROGMEM  short tvVolumeDownArrayCount = 70;
//
//PROGMEM  short tvOneArray[] = {4400,560,560,560,540,560,540,580,1640,580,540,560,540,560,560,560,560,560,1660,560,1640,580,1640,580,540,560,1660,560,1660,560,1660,560,1660,560,1660,560,540,560,560,560,540,560,1660,560,560,560,540,580,540,560,540,560,1660,560,1660,560,1660,560,560,560,1660,560,1660,560,1660,560,39060,8880,2220,560,29184,8900,2200,560};
//PROGMEM  short tvOneCount = 74;
//
//PROGMEM  short tvFourArray[] = {4420,600,520,600,500,620,480,620,1600,620,500,620,500,560,540,560,560,560,1660,560,1640,580,1640,580,540,560,1660,560,1660,560,1660,560,1660,560,540,580,540,560,1660,560,560,560,1640,580,540,560,540,580,540,560,1660,560,1660,560,560,560,1640,580,540,560,1660,560,1660,560,1660,560,39060,8920,2180,560,29184,8880,2220,560};
//PROGMEM  short tvFourCount = 74;
//
//PROGMEM  short tvSevenArray[] = {4420,600,500,620,500,600,500,620,1600,620,500,600,500,620,500,560,560,560,1640,580,1640,580,1640,560,560,560,1660,560,1660,560,1660,560,1660,560,1660,560,1660,560,1660,560,540,560,1660,560,560,560,540,560,560,560,540,560,560,560,540,580,1640,580,540,560,1660,560,1660,560,1640,580,38700,8880,2200,580,28824,8880,2200,560};
//PROGMEM  short tvSevenCount = 74;
//
//PROGMEM  short tvDashArray[] = {4380,600,500,620,500,600,500,620,1600,620,500,560,540,600,520,560,540,620,1620,560,1640,580,1640,580,540,560,1660,560,1660,560,1660,560,1660,560,540,580,1640,560,1660,560,1660,560,560,560,540,560,560,560,540,560,1660,560,560,560,540,560,560,560,1660,560,1660,560,1660,560,1660,560,38700,8880,2200,580,28824,8880,2200,560};
//PROGMEM  short tvDashCount = 74;
//
//PROGMEM  short tvTwoArray[] = {4360,620,500,600,500,620,500,600,1620,600,500,620,500,600,500,620,500,600,1620,600,1620,600,1620,600,500,620,1600,620,1600,620,1600,600,1620,600,520,600,1600,620,500,620,480,620,1600,620,500,600,520,560,540,600,1620,560,540,580,1640,580,1640,560,560,560,1660,560,1660,600,1620,560,39060,8880,2200,620,29144,8920,2160,600};
//PROGMEM  short tvTwoCount = 74;
//
//PROGMEM  short tvFiveArray[] = {4420,620,500,560,560,560,540,560,1660,560,540,580,540,560,540,560,560,560,1660,560,1660,560,1660,560,540,560,1660,560,1660,560,1660,560,1660,560,1660,560,560,560,1660,560,540,560,1660,560,560,560,540,560,560,560,540,560,1660,560,560,560,1660,560,540,560,1660,560,1660,560,1660,560,39060,8880,2220,560,29204,8960,2120,640};
//PROGMEM  short tvFiveCount = 74;
//
//PROGMEM  short tvEightArray[] = {4360,620,500,620,500,600,500,600,1620,600,520,600,500,620,500,600,500,620,1600,620,1600,600,1620,620,500,600,1600,620,1600,620,1600,620,1620,600,500,600,520,600,500,620,1600,620,1600,600,520,600,500,600,520,600,1600,620,1600,620,1600,620,500,600,520,600,1620,600,1600,620,1600,620,39020,8880,2220,600};
//PROGMEM  short tvEightCount = 70;
//
//PROGMEM  short tvZeroArray[] = {4380,620,500,600,500,620,480,620,1620,600,500,620,500,600,500,620,500,600,1600,620,1600,620,1600,620,500,600,1620,600,1620,600,1620,600,1620,600,500,620,500,600,520,600,500,600,1620,600,500,580,540,620,480,620,1600,580,1660,560,1640,580,1640,580,540,560,1660,560,1660,560,1660,560,39060,8880,2220,600,29144,8880,2220,600};
//PROGMEM  short tvZeroCount = 74;
//
//PROGMEM  short tvThreeArray[] = {4420,600,500,620,500,600,500,620,1600,620,500,560,540,580,540,560,540,620,1600,560,1660,560,1660,580,540,560,1660,560,1660,560,1660,560,1660,560,1660,560,1660,560,540,580,540,560,1660,560,540,560,560,560,540,560,560,560,540,580,1640,560,1660,560,560,560,1660,560,1660,560,1640,580,39060,8880,2220,600,29144,8880,2200,600};
//PROGMEM  short tvThreeCount = 74;
//
//PROGMEM  short tvSixArray[] = {4380,600,500,620,500,600,500,620,1600,620,500,600,500,620,500,600,500,620,1600,620,1600,620,1600,620,500,600,1620,600,1620,600,1600,580,1640,620,500,600,1620,600,1620,600,520,600,1600,620,500,600,500,620,500,600,1620,600,500,620,500,600,1620,600,500,620,1600,560,1660,560,1660,560,39060,8900,2200,560};
//PROGMEM  short tvSixCount = 70;
//
//PROGMEM  short tvNineArray[] = {4380,620,500,600,500,620,500,600,1620,600,500,620,500,600,500,620,500,600,1620,600,1620,600,1620,600,500,620,1600,620,1600,600,1620,600,1620,600,1620,600,500,620,500,620,1600,600,1620,600,500,620,500,600,500,620,500,600,1620,600,1620,600,500,620,500,600,1620,600,1620,600,1620,600,39020,8880,2220,560,29184,8880,2220,560};
//PROGMEM  short tvNineCount = 74;
//
//PROGMEM  short tvRetArray[] = {4380,600,500,620,500,600,500,620,1600,620,500,600,500,620,500,600,500,620,1600,620,1600,620,1600,620,500,600,1620,600,1620,600,1600,620,1600,620,500,600,500,620,1600,620,1600,620,500,600,500,620,500,620,480,620,1600,620,1600,620,500,600,500,620,1600,620,1600,620,1600,620,1600,620,39000,8880,2220,600};
//PROGMEM  short tvRetCount = 70;
//
//PROGMEM  short tvSrcArray[] = {4380,600,500,620,500,600,500,620,1600,620,500,600,500,620,500,560,540,620,1600,620,1600,560,1660,560,560,560,1660,560,1660,560,1640,580,1640,580,540,560,560,560,1660,560,540,560,560,560,540,560,1660,560,540,580,1640,580,1660,560,540,560,1660,560,1660,560,1660,560,540,560,1660,560,39080,8880,2200,620,29144,8880,2200,620};
//PROGMEM  short tvSrcCount = 74;
//
//PROGMEM  short tvMuteArray[] = {4380,600,520,600,500,620,480,620,1600,620,500,620,500,600,500,620,500,600,1620,600,1600,620,1600,620,500,600,1620,600,1620,600,1620,600,1620,620,1600,560,1660,600,500,560,1660,580,540,560,540,580,540,560,540,560,560,560,540,580,1660,560,540,560,1660,560,1660,560,1660,560,1660,560,39060,8880,2220,600};
//PROGMEM  short tvMuteCount = 70;
//
//PROGMEM  short tvMenuArray[] = {4420,600,500,620,500,600,520,600,1620,600,500,600,500,620,500,620,480,620,1600,620,1600,620,1600,620,500,600,1620,560,1660,600,1620,560,1660,560,1660,560,1660,560,1660,560,1660,560,1640,580,540,560,560,560,540,560,560,560,540,560,560,560,540,560,560,560,1660,560,1660,560,1640,580,39060,8920,2160,620,29124,8940,2160,600};
//PROGMEM  short tvMenuCount = 74;
//
//PROGMEM  short tvInfoArray[] = {4380,620,500,600,500,620,500,600,1620,600,500,620,500,600,500,620,500,600,1620,600,1620,600,1620,600,500,620,1600,620,1600,620,1600,620,1600,620,500,600,1620,600,1620,600,1620,560,1640,580,540,620,500,560,540,560,1660,560,560,560,540,560,560,560,540,620,1600,560,1660,560,1660,560,39060,8900,2200,620};
//PROGMEM  short tvInfoCount = 70;
//
//PROGMEM  short tvEPGArray[] = {4360,620,500,600,500,620,500,600,1620,620,480,620,500,620,480,620,500,600,1620,600,1620,600,1620,600,500,620,1600,620,1600,620,1600,620,1600,620,500,600,500,620,500,600,500,620,500,600,520,600,1600,620,500,620,1600,600,1620,600,1620,600,1620,600,1620,600,1620,600,500,620,1600,620,39020,8880,2200,560,29184,8900,2200,620};
//PROGMEM  short tvEPGCount = 74;
//
//PROGMEM  short tvExitArray[] = {4380,600,520,600,500,620,480,620,1600,620,500,600,500,620,500,600,520,600,1620,560,1640,580,1640,620,500,560,1660,600,1620,560,1660,560,1660,600,500,620,1600,620,500,600,1600,620,1620,600,500,620,500,600,500,620,1600,620,500,600,1600,620,500,620,500,600,1620,600,1620,600,1620,600,39020,8880,2200,620,29144,8880,2200,620};
//PROGMEM  short tvExitCount = 74;
//
//PROGMEM  short tvUpArray[] = {4320,660,460,640,480,640,460,640,1580,640,480,640,460,640,480,640,460,640,1580,640,1580,640,1580,640,480,640,1580,640,1560,660,1560,640,1580,640,480,640,1580,640,1580,640,460,660,460,640,460,640,480,640,460,640,1580,660,460,640,460,660,1560,640,1580,640,1580,640,1580,640,1580,640,38980,8980,2120,640};
//PROGMEM  short tvUpCount = 70;
//
//PROGMEM  short tvLeftArray[] = {4340,620,500,600,500,620,500,620,1600,600,500,620,500,600,500,620,500,600,1620,600,1620,600,1620,600,500,620,1600,620,1600,620,1600,620,1600,620,1600,620,500,600,500,620,500,600,500,620,500,600,1620,600,500,620,500,600,1620,600,1600,620,1620,600,1620,600,1620,600,500,560,1660,600,39020,8880,2220,600};
//PROGMEM  short tvLeftCount = 70;
//
//PROGMEM  short tvRightArray[] = {4340,640,460,640,480,640,460,640,1580,640,480,640,460,640,480,640,480,620,1580,640,1580,640,1580,620,500,600,1620,600,1620,620,1600,600,1620,600,1620,600,1620,600,500,620,500,600,500,640,480,620,1600,600,500,620,500,600,520,600,1600,620,1600,620,1600,620,1600,620,500,600,1620,600,39020,8920,2180,600};
//PROGMEM  short tvRightCount = 70;
//
//PROGMEM  short tvOkayArray[] = {4360,620,500,620,480,620,500,600,1620,600,500,620,500,600,520,600,500,620,1600,620,1600,600,1620,600,500,620,1600,620,1600,620,1600,600,1620,620,500,600,1620,600,500,620,500,600,500,620,500,600,1620,600,500,620,1600,620,500,600,1620,600,1620,600,1620,600,1620,560,540,560,1660,560,39060,8900,2200,600};
//PROGMEM  short tvOkayCount = 70;
//
//PROGMEM  short tvDownArray[] = {4420,600,520,600,500,620,500,600,1600,620,500,620,480,620,500,600,520,600,1620,600,1620,600,1600,620,500,600,1620,600,1620,600,1620,600,1620,600,1620,560,1660,560,1660,560,540,560,540,580,540,620,500,560,540,600,520,560,540,600,520,600,1620,600,1600,620,1600,580,1640,620,1600,560,39080,8880,2200,620};
//PROGMEM  short tvDownCount = 70;
//
//PROGMEM  short tvChUpArray[] = {4380,600,500,620,500,600,520,600,1600,620,500,600,500,620,500,600,500,620,1600,620,1600,620,1600,620,500,600,1620,600,1620,600,1620,600,1620,600,500,620,1600,620,500,600,500,620,500,600,500,620,500,600,500,620,1600,620,500,600,1620,600,1620,560,1660,560,1660,560,1660,560,1660,560,39060,8880,2220,560,29184,8900,2200,560};
//PROGMEM  short tvChUpCount = 74;
//
//PROGMEM  short tvChDownArray[] = {4340,640,480,620,480,640,480,620,1600,620,480,620,500,600,500,620,500,600,1620,600,1620,600,1620,600,500,620,1600,620,1600,600,1620,600,1620,600,1620,600,1620,620,480,620,500,600,500,620,500,600,520,600,500,600,500,620,500,620,1600,600,1620,600,1620,600,1620,600,1620,600,1620,600,39020,8880,2220,600};
//PROGMEM  short tvChDownCount = 70;
//
//PROGMEM  short tvCCArray[] = {4440,600,500,600,520,600,500,560,1660,560,560,580,520,560,560,600,500,560,1660,560,1660,560,1660,560,560,560,1660,560,1660,560,1660,560,1640,580,540,560,560,560,540,560,560,560,1660,560,540,560,1660,560,560,560,1660,560,1660,560,1660,560,1640,580,540,560,1660,560,560,560,1640,560,39080,8900,2200,560};
//PROGMEM  short tvCCCount = 70;
//
//PROGMEM  short tvAspectArray[] = {4420,600,500,620,500,600,520,600,1600,620,500,620,480,620,500,600,520,600,1620,600,1620,600,1600,620,500,600,1620,600,1620,600,1620,600,1620,560,1660,560,1660,560,1660,560,540,560,560,600,500,580,1640,580,540,560,540,560,560,560,540,580,1660,560,1640,580,1640,580,540,560,1660,560,39060,8880,2220,560,29184,8880,2220,600};
//PROGMEM  short tvAspectCount = 74;
//
//PROGMEM  short tvFavArray[] = {4440,560,540,560,560,560,540,560,1660,560,540,580,540,560,560,560,540,560,1660,560,1660,560,1660,560,540,580,1640,560,1660,560,1660,560,1660,580,540,560,540,580,540,560,540,560,560,560,1660,560,540,580,540,560,1660,560,1660,560,1660,560,1660,560,1640,580,540,560,1660,560,1660,560,39060,8880,2200,580,29184,8880,2200,560};
//PROGMEM  short tvFavCount = 74;
//
//PROGMEM  short tvMTSArray[] = {4360,640,460,640,480,640,460,640,1580,640,480,640,460,640,480,640,460,640,1580,640,1580,640,1580,640,480,640,1580,640,1580,640,1580,640,1560,660,1560,660,460,640,480,640,460,640,1580,640,480,640,1560,660,460,640,460,660,1560,660,1580,640,1560,660,460,640,1580,640,460,640,1580,640,39000,8960,2120,660,29104,8960,2120,640};
//PROGMEM  short tvMTSCount = 74;
//
//PROGMEM  short tvPModeArray[] = {4340,640,480,640,480,620,480,640,1580,640,460,660,460,640,460,640,480,640,1580,640,1580,640,1580,640,460,640,1580,640,1580,640,1580,640,1580,640,1580,640,1580,620,1600,620,1600,620,500,600,500,620,500,600,500,620,500,600,500,620,500,600,500,620,1600,620,1600,620,1600,620,1600,620,39020,8880,2200,620};
//PROGMEM  short tvPModeCount = 70;
//
//PROGMEM  short tvAddEraseArray[] = {4420,560,540,560,540,580,540,560,1660,560,560,560,540,560,560,560,540,560,1660,560,1660,560,1660,560,540,560,1660,580,1640,580,1640,580,1640,560,560,560,540,560,1660,560,1660,560,560,560,540,580,1640,560,560,560,1660,560,1640,580,540,560,560,560,1660,560,1660,560,540,560,1660,560,39060,8880,2220,560,29184,8880,2200,620};
//PROGMEM  short tvAddEraseCount = 74;
//
//PROGMEM  short tvFRZArray[] = {4400,620,500,600,520,600,500,620,1600,620,500,600,500,620,500,600,500,620,1600,600,1620,600,1620,620,480,620,1600,620,1600,620,1620,600,1620,560,540,600,1620,560,540,580,540,560,1660,560,560,560,1660,560,540,560,1660,560,540,580,1640,560,1660,580,540,560,1660,560,540,580,1640,560,39080,8880,2220,600};
//PROGMEM  short tvFRZCount = 70;
//
//PROGMEM  short tvSModeArray[] = {4380,600,520,600,500,620,500,600,1620,600,500,620,500,600,500,620,500,600,1620,600,1600,620,1600,620,500,620,1600,600,1620,600,1620,600,1620,620,480,620,1600,620,1600,620,1600,620,500,600,500,620,1600,620,500,600,1620,600,500,620,500,600,500,620,1600,620,1600,620,500,560,1660,560,39060,8880,2220,600,29144,8880,2200,620};
//PROGMEM  short tvSModeCount = 74;
//
//PROGMEM  short tvFavMinusArray[] = {4340,640,460,660,460,640,460,660,1560,640,480,640,460,640,480,640,480,640,1560,660,1560,660,1560,640,480,640,1580,640,1580,640,1580,640,1580,640,460,640,1580,640,480,640,1560,660,460,640,480,640,460,640,480,640,1580,640,460,640,1580,640,480,640,1580,620,1600,620,1600,620,1580,640,39000,8920,2160,620};
//PROGMEM  short tvFavMinusCount = 70;
//
//PROGMEM  short tvChlistArray[] = {4420,620,500,600,500,620,500,600,1620,600,500,620,500,600,500,620,500,600,1620,600,1600,620,1600,620,500,600,1620,600,1620,600,1620,600,1620,620,1600,600,1620,600,500,620,500,600,1620,600,500,620,1600,620,500,600,500,620,500,600,1620,600,1620,600,500,620,1600,620,500,600,1620,600,39020,8880,2220,600,29124,8900,2200,620};
//PROGMEM  short tvChlistCount = 74;
//
//PROGMEM  short tvSleepArray[] = {4420,560,560,560,560,560,540,560,1660,560,540,580,540,560,540,560,560,560,1660,560,1660,560,1660,560,540,580,1640,560,1660,560,1660,560,1660,560,1660,560,560,560,540,560,560,560,540,560,1660,560,540,580,540,560,560,560,1660,560,1660,560,1640,580,1640,580,540,560,1660,560,1660,560,39060,8880,2200,580,29184,8880,2200,620};
//PROGMEM  short tvSleepCount = 74;
//
//PROGMEM  short tvFavPlusArray[] = {4420,560,560,560,540,560,560,560,1660,560,540,560,560,560,540,560,560,560,1660,560,1660,560,1640,580,540,560,1660,560,1660,560,1660,560,1660,560,1660,560,540,580,540,560,1660,560,540,560,560,560,540,560,560,560,540,560,1660,560,1660,560,560,560,1660,560,1640,580,1640,580,1640,560,39060,8900,2200,560};
//PROGMEM  short tvFavPlusCount = 70;
//
//
//
////FIREPLACE INFO
//PROGMEM  short fireplacePowerArray[] = {1220,1260,380,1260,400,420,1220,420,1220,1260,380,440,1220,420,1220,1260,380,440,1220,420,1220,440,34220,440,1220,1260,380,1260,380,440,1220,420,1220,1260,380,440,1200,440,1220,1260,380,420,1220,440,1200,440};
//PROGMEM  short fireplacePowerCount = 46;
//
//PROGMEM  short fireplaceFireArray[] = {1200,1260,400,1260,380,440,1200,440,1220,1240,400,440,1200,440,1220,420,1220,420,1220,1260,380,440,34240,420,1220,1260,380,1260,400,420,1220,420,1220,1260,400,420,1220,420,1220,440,1220,420,1220,1260,380,440};
//PROGMEM  short fireplaceFireCount = 46;
//
//PROGMEM  short fireplaceClockArray[] = {1220,1260,380,1260,380,440,1220,420,1220,1260,380,1260,400,420,1220,420,1220,440,1200,440,1220,420,34240,440,1200,1260,400,1260,380,420,1220,440,1200,1260,400,1260,380,440,1200,440,1220,420,1220,440,1200,440};
//PROGMEM  short fireplaceClockCount = 46;
//
//PROGMEM  short fireplaceLightArray[] = {1160,1300,340,1320,320,480,1160,1320,340,480,1160,480,1160,500,1160,480,1160,480,1160,1320,340,480,34180,480,1160,1320,340,1300,340,480,1160,1320,320,500,1160,480,1160,480,1160,500,1140,500,1160,1300,340,480};
//PROGMEM  short fireplaceLightCount = 46;
//
//PROGMEM  short fireplaceHeatArray[] = {1220,1260,380,1260,400,420,1220,1260,380,440,1220,1240,400,420,1220,440,1200,440,1220,420,1220,420,34240,440,1220,1240,400,1260,380,440,1200,1260,400,420,1220,1260,380,440,1220,420,1220,440,1200,440,1220,420};
//PROGMEM  short fireplaceHeatCount = 46;

//SOUNDBAR INFO
//PROGMEM short soundbarPowerArray[] = {800,500,780,500,360,500,360,1360,1200,500,360,500,360,940,780,500,360,500,360,500,360,500,340,500,360,500,360,500,360,940,360,500,780,500,360,500,17484,2640,840,500,780,480,380,480,360,1340,1240,500,360,500,360,920,800,500,360,480,380,500,340,500,360,500,360,500,360,500,360,900,400,500,780,500,360,500};
//PROGMEM short soundbarCOAXArray[] = {880,500,780,500,360,500,360,1280,1280,500,360,500,360,920,800,500,360,500,360,480,380,500,360,480,380,860,420,520,340,520,760,460,400,860,17984,2600,880,500,780,440,420,440,420,1280,1280,460,400,460,400,860,860,460,400,440,420,460,400,440,420,440,420,860,420,520,340,520,780,440,400,860,17984,2600,880,500,780,500,360,500,360,1280,1280,500,360,500,360,860,860,500,360,440,420,500,360,440,420,480,380,860,440,500,340,520,780,440,400,860};
//PROGMEM short soundbarBLUETOOTHArray[] =  {840,500,780,500,360,500,360,480,800,920,380,480,360,500,360,920,800,500,360,500,360,500,360,500,360,900,400,500,780,900,820,500,360,900,17944,2640,820,520,780,500,340,500,360,500,800,900,380,500,360,500,360,900,820,500,360,500,360,500,360,500,360,900,400,500,780,900,820,480,380,900};
//PROGMEM short soundbarAUXArray[] = {260,840,0,60,20,40,20,80,160,360,0,260,0,3600,40,60,20,120,100,1440,0,860,280,120,360,40,20,20,320,20,40,140,980,200,10340,160,600,480,0,1904,20,80,6420,9944,0,20,0,11820,0,2680,20,1160,20,40,0,780,0,15960,0,80,0,100};
//PROGMEM short soundbarPLUSArray[] = 
//PROGMEM short soundbarMUTEArray[] = 
//PROGMEM short soundbarMINUSArray[] = 
//PROGMEM short soundbarOPTArray[] = 
//PROGMEM short soundbarSURRArray[] = 
//PROGMEM short soundbarUSBArray[] = 
//PROGMEM short soundbarBASSMINUSArray[] = 
//PROGMEM short soundbarBASSRESETArray[] = 
//PROGMEM short soundbarBASSPLUSArray[] = 
//PROGMEM short soundbarTREBMINUSArray[] = 
//PROGMEM short soundbarTREBRESETArray[] = 
//PROGMEM short soundbarTREBPLUSArray[] = 

void setup() {
  Serial.begin(115200);  
  inputString.reserve(100);  
  Serial.write("START ");
  
  // SET AS OUTPUT
  //remotes
  pinMode(AppleIRledPin, OUTPUT); 
  pinMode(tvIRledPin, OUTPUT);     
  pinMode(fireplaceIRledPin, OUTPUT); 
  
  //indicator
  pinMode(indicatorPin,OUTPUT);

  //lights
  pinMode(porchLight, OUTPUT); 
  pinMode(dinningRoomLight, OUTPUT);     
  pinMode(livingRoomLight, OUTPUT); 
  pinMode(bedroomLight, OUTPUT); 
  pinMode(kitchenLight, OUTPUT);     
 
  

  //blinds  
  pinMode(blindsStop, OUTPUT); 
  pinMode(blindsDown, OUTPUT); 
  pinMode(blindsUp, OUTPUT);   
  
  //SET INITIAL VALUES
  //remotes
  digitalWrite(AppleIRledPin, LOW); 
  digitalWrite(tvIRledPin, LOW);     
  digitalWrite(fireplaceIRledPin, LOW); 
  
  //indicator
  digitalWrite(indicatorPin,LOW);

  //lights
  digitalWrite(porchLight, LOW); 
//  delay(1000);
  digitalWrite(dinningRoomLight, LOW); 
//  delay(1000);    
  digitalWrite(livingRoomLight, LOW); 
//  delay(1000);
  digitalWrite(bedroomLight, LOW); 
//  delay(1000);
  digitalWrite(kitchenLight, LOW);  
//  delay(1000);   
 
  
  //TV
//  digitalWrite(tvMotorPowerPin, LOW); 
//  digitalWrite(tvMotorDirPin, LOW);   

  //blinds  
  digitalWrite(blindsStop, HIGH); 
  digitalWrite(blindsDown, HIGH); 
  digitalWrite(blindsUp, HIGH); 
  
  
  flashIndicator(100,4);
}


void loop()
{
  if (stringComplete) {
    char input[50] ;
    inputString.toCharArray(input,50);
    Serial.write(input); 

    
   //APPLE JOBS
//    if(inputString =="APPLE_UP"){
//      sendRemoteSignal(appleUpArray,appleUpArrayCount,AppleIRledPin);
//    }
//    if(inputString  == "APPLE_DOWN"){
//      sendRemoteSignal(appleDownArray,appleDownArrayCount,AppleIRledPin);
//    }
//    if(inputString  == "APPLE_LEFT"){
//      sendRemoteSignal(appleLeftArray,appleLeftArrayCount,AppleIRledPin);
//    }
//    if(inputString  == "APPLE_RIGHT"){
//      sendRemoteSignal(appleRightArray,appleRightArrayCount,AppleIRledPin);
//    }
//    if(inputString  == "APPLE_MENU"){
//      sendRemoteSignal(appleMenuArray,appleMenuArrayCount,AppleIRledPin);
//    }
//    if(inputString  == "APPLE_OKAY"){
//      sendRemoteSignal(appleOkayArray,appleOkayArrayCount,AppleIRledPin);
//    }
//    if(inputString  == "APPLE_PLAY_PAUSE"){
//      sendRemoteSignal(applePausePlayArray,applePausePlayArrayCount,AppleIRledPin);
//    }
//    
//    //TV JOBS
//    if(inputString  == "TV_POWER"){
//      sendRemoteSignal(tvPowerArray,tvPowerArrayCount,tvIRledPin);
//    }
//    if(inputString  == "TV_VOLUME_UP"){
//      sendRemoteSignal(tvVolumeUpArray,tvVolumeUpArrayCount,tvIRledPin);
//    }
//    if(inputString  == "TV_VOLUME_DOWN"){
//      sendRemoteSignal(tvVolumeDownArray,tvVolumeDownArrayCount,tvIRledPin);
//    }
//    if(inputString  == "TV_ONE"){
//      sendRemoteSignal(tvOneArray,tvOneCount,tvIRledPin);
//    }
//    if(inputString  == "TV_FOUR"){
//      sendRemoteSignal(tvFourArray,tvFourCount,tvIRledPin);
//    }
//    if(inputString  == "TV_SEVEN"){
//      sendRemoteSignal(tvSevenArray,tvSevenCount,tvIRledPin);
//    }
//    if(inputString  == "TV_DASH"){
//      sendRemoteSignal(tvDashArray,tvDashCount,tvIRledPin);
//    }
//    if(inputString  == "TV_TWO"){
//      sendRemoteSignal(tvTwoArray,tvTwoCount,tvIRledPin);
//    }
//    if(inputString  == "TV_THREE"){
//      sendRemoteSignal(tvThreeArray,tvThreeCount,tvIRledPin);
//    }
//    if(inputString  == "TV_FIVE"){
//      sendRemoteSignal(tvFiveArray,tvFiveCount,tvIRledPin);
//    }
//    if(inputString  == "TV_SIX"){
//      sendRemoteSignal(tvSixArray,tvSixCount,tvIRledPin);
//    }
//    if(inputString  == "TV_EIGHT"){
//      sendRemoteSignal(tvEightArray,tvEightCount,tvIRledPin);
//    }
//    if(inputString  == "TV_NINE"){
//      sendRemoteSignal(tvNineArray,tvNineCount,tvIRledPin);
//    }
//    if(inputString  == "TV_ZERO"){
//      sendRemoteSignal(tvZeroArray,tvZeroCount,tvIRledPin);
//    }
//    if(inputString  == "TV_RETURN"){
//      sendRemoteSignal(tvRetArray,tvRetCount,tvIRledPin);
//    }
//    if(inputString  == "TV_FAV"){
//      sendRemoteSignal(tvFavArray,tvFavCount,tvIRledPin);
//    }
//    if(inputString  == "TV_ADD_ERASE"){
//      sendRemoteSignal(tvAddEraseArray,tvAddEraseCount,tvIRledPin);
//    }
//    if(inputString  == "TV_FAV_MINUS"){
//      sendRemoteSignal(tvFavMinusArray,tvFavMinusCount,tvIRledPin);
//    }
//    if(inputString  == "TV_FAV_PLUS"){
//      sendRemoteSignal(tvFavPlusArray,tvFavPlusCount,tvIRledPin);
//    }
//    if(inputString  == "TV_CH_UP"){
//      sendRemoteSignal(tvChUpArray,tvChUpCount,tvIRledPin);
//    }
//    if(inputString  == "TV_CH_DOWN"){
//      sendRemoteSignal(tvChDownArray,tvChDownCount,tvIRledPin);
//    }
//    if(inputString  == "TV_CHLIST"){
//      sendRemoteSignal(tvChlistArray,tvChlistCount,tvIRledPin);
//    }
//    if(inputString  == "TV_MENU"){
//      sendRemoteSignal(tvMenuArray,tvMenuCount,tvIRledPin);
//    }
//    if(inputString  == "TV_INFO"){
//      sendRemoteSignal(tvInfoArray,tvInfoCount,tvIRledPin);
//    }
//    if(inputString  == "TV_EPG"){
//      sendRemoteSignal(tvEPGArray,tvEPGCount,tvIRledPin);
//    }
//    if(inputString  == "TV_EXIT"){
//      sendRemoteSignal(tvExitArray,tvExitCount,tvIRledPin);
//    }
//    if(inputString  == "TV_MENU_LEFT"){
//      sendRemoteSignal(tvLeftArray,tvLeftCount,tvIRledPin);
//    }
//    if(inputString  == "TV_MENU_DOWN"){
//      sendRemoteSignal(tvDownArray,tvDownCount,tvIRledPin);
//    }
//    if(inputString  == "TV_MENU_RIGHT"){
//      sendRemoteSignal(tvRightArray,tvRightCount,tvIRledPin);
//    }
//    if(inputString  == "TV_PMODE"){
//      sendRemoteSignal(tvPModeArray,tvPModeCount,tvIRledPin);
//    }
//    if(inputString  == "TV_SMODE"){
//      sendRemoteSignal(tvSModeArray,tvSModeCount,tvIRledPin);
//    }
//    if(inputString  == "TV_SLEEP"){
//      sendRemoteSignal(tvSleepArray,tvSleepCount,tvIRledPin);
//    }
//    if(inputString  == "TV_ASPECT"){
//      sendRemoteSignal(tvAspectArray,tvAspectCount,tvIRledPin);
//    }
//    if(inputString  == "TV_CC"){
//      sendRemoteSignal(tvCCArray,tvCCCount,tvIRledPin);
//    }
//    if(inputString  == "TV_MTS"){
//      sendRemoteSignal(tvMTSArray,tvMTSCount,tvIRledPin);
//    }
//    if(inputString  == "TV_FREEZE"){
//      sendRemoteSignal(tvFRZArray,tvFRZCount,tvIRledPin);
//    }
//    if(inputString  == "TV_SRC"){
//      sendRemoteSignal(tvSrcArray,tvSrcCount,tvIRledPin);
//    }
//    if(inputString  == "TV_MUTE"){
//      sendRemoteSignal(tvMuteArray,tvMuteCount,tvIRledPin);
//    }
//    if(inputString  == "TV_MENU_UP"){
//      sendRemoteSignal(tvUpArray,tvUpCount,tvIRledPin);
//    }
//    if(inputString  == "TV_MENU_OKAY"){
//      sendRemoteSignal(tvOkayArray,tvOkayCount,tvIRledPin);
//    }
//    
//    //FIREPLACE JOBS
//    
//    if(inputString  == "ELECTRONICS_FIREPLACE_POWER"){
//      sendRemoteSignal(fireplacePowerArray,fireplacePowerCount,fireplaceIRledPin);
//    }
//    if(inputString  == "ELECTRONICS_FIREPLACE_HEAT"){
//      sendRemoteSignal(fireplaceHeatArray,fireplaceHeatCount,fireplaceIRledPin);
//    }
//    if(inputString  == "ELECTRONICS_FIREPLACE_TIMER"){
//      sendRemoteSignal(fireplaceClockArray,fireplaceClockCount,fireplaceIRledPin);
//    }
//    if(inputString  == "ELECTRONICS_FIREPLACE_FIRE"){
//      sendRemoteSignal(fireplaceFireArray,fireplaceFireCount,fireplaceIRledPin);
//    }
//    if(inputString  == "ELECTRONICS_FIREPLACE_LIGHT"){
//      sendRemoteSignal(fireplaceLightArray,fireplaceLightCount,fireplaceIRledPin);
//    }
//    if(inputString  == "ELECTRONICS_FIREPLACE_DEV_OPEN"){
//      //open_devies();
//    }
//    if(inputString  == "ELECTRONICS_FIREPLACE_DEV_CLOSE"){
//      //close_devices();
//    }
//    if(inputString  == "FIREPLACE_TV_UP"){
//      tvUp();
//    }
//    if(inputString  == "FIREPLACE_TV_DOWN"){
//      tvDown();
//    }
    
    //ELECTRONIC DEVICES
      
    if(inputString.endsWith("ELECTRONICS_BLINDS_UP")){
      click_blinds_button(blindsUp,6000);
      flashIndicator(500,1);
    }
    if(inputString.endsWith( "ELECTRONICS_BLINDS_STOP")){
      click_blinds_button(blindsStop,6000);
      flashIndicator(500,2);
    }
    if(inputString.endsWith("ELECTRONICS_BLINDS_DOWN")){
      click_blinds_button(blindsDown,6000);
      flashIndicator(500,3);
    }
    if(inputString.endsWith("ELECTRONICS_BEDROOM_LIGHTS")){
      changeRelay(bedroomLight);
      flashIndicator(500,4);
    }
    if(inputString.endsWith("ELECTRONICS_LIVINGROOM_LIGHTS")){
      changeRelay(livingRoomLight);
      flashIndicator(500,5);
    }
    if(inputString.endsWith("ELECTRONICS_KITCHENK_LIGHTS")){
      changeRelay(kitchenLight);
      flashIndicator(500,6);
    }
    if(inputString.endsWith("ELECTRONICS_DINING_LIGHTS")){
      changeRelay(dinningRoomLight);
      flashIndicator(500,7);
    }
    if(inputString.endsWith("ELECTRONICS_PATIO_LIGHTS")){
      changeRelay(porchLight);
      flashIndicator(500,8);
    }
      
      //clear data
    inputString = "";
    stringComplete = false;
  }
}


void pulseIR(long microsecs,int pin) {
  // we'll count down from the number of microseconds we are told to wait
 
  cli();  // this turns off any background interrupts
 
  while (microsecs > 0) {
    // 38 kHz is about 13 microseconds high and 13 microseconds low
   digitalWrite(pin, HIGH);  // this takes about 3 microseconds to happen
   delayMicroseconds(10);         // hang out for 10 microseconds, you can also change this to 9 if its not working
   digitalWrite(pin, LOW);   // this also takes about 3 microseconds
   delayMicroseconds(10);         // hang out for 10 microseconds, you can also change this to 9 if its not working
 
   // so 26 microseconds altogether
   microsecs -= 26;
  }
 
  sei();  // this turns them back on
}

void sendRemoteSignal(short values[],short arraySize,int pin){
  boolean isOFF = false;
  
  for(int i = 0; i < arraySize; i++){
    int v = values[i];
    
    if(isOFF){
          delayMicroseconds(v);
    }else{
          pulseIR(v,pin);
    }
				
    isOFF = !isOFF;
  }
  
}

void click_blinds_button(int button,int del){
  digitalWrite(button,LOW);
  delay(500);
  digitalWrite(button,HIGH);
  
//  delay(del);
//  
//  digitalWrite(blindsStop,LOW);
//  delay(500);
//  digitalWrite(blindsStop,HIGH);
}


void changeRelay(int relayPin){
  digitalWrite(relayPin, !digitalRead(relayPin));
}
    
void flashIndicator(int time, int rep){
    for(int i = 0; i < rep; i++){
      digitalWrite(indicatorPin,HIGH);
      delay(time);
      digitalWrite(indicatorPin,LOW);
      delay(70);
  }
}
void serialEvent() {
  boolean wordFound = false;
  while (Serial.available() and !wordFound) {
    // get the new byte:
    char inChar = (char)Serial.read();
   
    // add it to the inputString:
    if(isValidChar(inChar)){
      inputString += inChar;
    }
    // if the incoming character is a newline, set a flag
    // so the main loop can do something about it:
    if (inChar == '\n' || inChar == ';') {
      
      char input[50] ;
      inputString.toCharArray(input,50);
      wordFound = true;
      stringComplete = true;
    } 
  }
}

boolean isValidChar(char c){
  int ci = c+0;
  
  //see if letter is capital
  if(ci>=65 && ci<=90)
    return true;
 
   //see if letter is lower case
  if(ci>=97 && ci<=122)
    return true;
   
   
  //see if letter is an underscore
  if(ci == 95)
    return true;
    
  return false;
  
  
}
