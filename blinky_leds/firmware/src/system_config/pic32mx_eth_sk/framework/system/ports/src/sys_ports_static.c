
#include "system_config.h"
#include "peripheral/ports/plib_ports.h"


void SYS_PORTS_Initialize(void)
{
    /* AN and CN Pins Initialization */
    PLIB_PORTS_AnPinsModeSelect(PORTS_ID_0, SYS_PORT_AD1PCFG, PORTS_PIN_MODE_DIGITAL);
    PLIB_PORTS_CnPinsPullUpEnable(PORTS_ID_0, SYS_PORT_CNPUE);
    PLIB_PORTS_CnPinsEnable(PORTS_ID_0, SYS_PORT_CNEN);
    PLIB_PORTS_ChangeNoticeEnable(PORTS_ID_0);
    
    
    /* PORT D Initialization */
    PLIB_PORTS_DirectionOutputSet( PORTS_ID_0, PORT_CHANNEL_B,  0x8088);  // B7 and B15 digital output
    //PLIB_PORTS_OpenDrainEnable(PORTS_ID_0, PORT_CHANNEL_D, SYS_PORT_D_ODC);
    PLIB_PORTS_Write (PORTS_ID_0, PORT_CHANNEL_B, 0x8088);
}


/*******************************************************************************
 End of File
*/
