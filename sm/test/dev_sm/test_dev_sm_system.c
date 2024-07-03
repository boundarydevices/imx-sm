/*
** ###################################################################
**
** Copyright 2024 NXP
**
** Redistribution and use in source and binary forms, with or without modification,
** are permitted provided that the following conditions are met:
**
** o Redistributions of source code must retain the above copyright notice, this list
**   of conditions and the following disclaimer.
**
** o Redistributions in binary form must reproduce the above copyright notice, this
**   list of conditions and the following disclaimer in the documentation and/or
**   other materials provided with the distribution.
**
** o Neither the name of the copyright holder nor the names of its
**   contributors may be used to endorse or promote products derived from this
**   software without specific prior written permission.
**
** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
** ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
** WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
** DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
** ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
** (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
** LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
** ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
** SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
**
**
** ###################################################################
*/

/*==========================================================================*/
/* Unit test for the device SM system API.                                  */
/*==========================================================================*/

/* DEV_00010 */

/* Include Config */

/* Includes */

#include "test.h"
#include "dev_sm.h"

/* Local defines */

/* Local types */

/* Local variables */

/* Local functions */

/*--------------------------------------------------------------------------*/
/* Test device SM system                                                    */
/*--------------------------------------------------------------------------*/
void TEST_DevSmSystem(void)
{
    printf("**** Device SM System API Tests ***\n\n");

#ifdef SIMU
    /* Reset Coverage */
    {
        /* Call for a reset */
        printf("DEV_SM_SystemReset(%u, %u)\n", 1U, 1U);
        CHECK(DEV_SM_SystemReset());
    }

    /* Shutdown and Stage Reset Coverage */
    {
        printf("DEV_SM_SystemStageReset()\n");
        CHECK(DEV_SM_SystemStageReset(0U, 0U));

        printf("DEV_SM_SystemShutdown()\n");
        CHECK(DEV_SM_SystemShutdown());
    }

    /*System Init Coverage */
    {
        printf("DEV_SM_SystemInit()\n");
        CHECK(DEV_SM_SystemInit());
    }

    /*SystemShutdownRecSet Coverage */
    {
        dev_sm_rst_rec_t shutdownRec = {0};

        printf("DEV_SM_SystemShutdownRecSet()\n");
        DEV_SM_SystemShutdownRecSet(shutdownRec);
    }

    /*Complete System Reset Processing Coverage*/
    {
        dev_sm_rst_rec_t rst = {0};

        printf("DEV_SM_SystemRstComp()\n");
        CHECK(DEV_SM_SystemRstComp(&rst));
    }

    /*System Error Coverage */
    {
        uint32_t status = 0, pc = 0x800U;
        printf("DEV_SM_System()\n");
        DEV_SM_SystemError(status, pc);
    }

    /*System Idle Coverage */
    {
        printf("DEV_SM_System()\n");
        CHECK(DEV_SM_SystemIdle());
    }

    /*Syslog dump Coverage */
    {
        uint32_t flags = 0x0U;
        printf("DEV_SM_SyslogDump()\n");
        CHECK(DEV_SM_SyslogDump(flags));
    }

    /*Fuse Word Address Get Coverage */
    {
        uint32_t fuseWord = 0x0U, addr = 0x0U;
        printf("DEV_SM_FuseInfoGet()\n");
        NECHECK(DEV_SM_FuseInfoGet(fuseWord, &addr), SM_ERR_NOT_SUPPORTED);
    }

    /* trigger software interrupt test */
    {
        SWI_Trigger();
    }
#endif

    printf("\n");
}

