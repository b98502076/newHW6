

#include "system_config.h"
#include "system_definitions.h"
#include "app.h"
#include<xc.h> // processor SFR definitions
#include<sys/attribs.h> // __ISR macro
// DEVCFGs here
// DEVCFG0
#pragma config DEBUG = OFF// no debugging
#pragma config JTAGEN = OFF // no jtag
#pragma config ICESEL = ICS_PGx1 // use PGED1 and PGEC1
#pragma config PWP = OFF // no write protect
#pragma config BWP = OFF // not boot write protect
#pragma config CP = OFF // no code protect

// DEVCFG1
#pragma config FNOSC = PRIPLL // use primary oscillator with pll
#pragma config FSOSCEN = OFF // turn off secondary oscillator
#pragma config IESO = OFF // no switching clocks
#pragma config POSCMOD = HS // high speed crystal mode
#pragma config OSCIOFNC = OFF // free up secondary osc pins
#pragma config FPBDIV = DIV_1 // divide CPU freq by 1 for peripheral bus clock
#pragma config FCKSM = CSDCMD // do not enable clock switch
#pragma config WDTPS = PS1 // slowest wdt
#pragma config WINDIS = OFF // no wdt window
#pragma config FWDTEN = OFF // wdt off by default
#pragma config FWDTWINSZ = WINSZ_25 // wdt window at 25%

// DEVCFG2 - get the CPU clock to 40MHz
#pragma config FPLLIDIV = DIV_2 // divide input clock to be in range 4-5MHz  DIVID BY 4
#pragma config FPLLMUL = MUL_20 // multiply clock after FPLLIDIV   times 20
#pragma config UPLLIDIV = DIV_1 // divide clock after FPLLMUL     divid by 1
#pragma config UPLLEN = ON // USB clock on
#pragma config FPLLODIV = DIV_2 // divide clock by 1 to output on pin

// DEVCFG3
#pragma config USERID = 0 // some 16bit userid
#pragma config PMDL1WAY = 1 // not multiple reconfiguration, check this
#pragma config IOL1WAY = 1 // not multimple reconfiguration, check this
#pragma config FUSBIDIO = 1 // USB pins controlled by USB module
#pragma config FVBUSONIO = 1 // controlled by USB module



/* Structure to hold the object handles for the modules in the system. */
SYSTEM_OBJECTS sysObj;


/*** System Device Control Initialization Data ***/

const SYS_DEVCON_INIT sysDevconInit =
{
    .moduleInit = {0},
};



void SYS_Initialize ( void* data )
{
    /* Core Processor Initialization */
    SYS_CLK_Initialize( NULL );
    sysObj.sysDevcon = SYS_DEVCON_Initialize(SYS_DEVCON_INDEX_0, (SYS_MODULE_INIT*)&sysDevconInit);
    SYS_DEVCON_PerformanceConfig(SYS_CLK_SystemFrequencyGet());
    SYS_DEVCON_JTAGDisable();

    /* Board Support Package Initialization */
    BSP_Initialize();

    /* System Services Initialization */    
    SYS_PORTS_Initialize();

    /* Initialize Drivers */

    /* Initialize System Services */


    /* Initialize Middleware */

    /* Initialize the Application */
    APP_Initialize();
}

/*******************************************************************************
 End of File
*/

