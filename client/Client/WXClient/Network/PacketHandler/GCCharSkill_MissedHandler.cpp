#include "StdAfx.h"
#include "TDTimeSystem.h"
#include "..\..\Procedure\GameProcedure.h"
#include "..\..\Object\ObjectManager.h"
#include "..\..\Object\Object.h"
#include "..\..\GameCommand.h"
#include "..\..\Object\ObjectCommandDef.h"
#include "..\..\Object\Character\Obj_Character.h"

#include "GCDetailBuff.h"
#include "gamestruct_impact.h"

#include "GCCharSkill_Missed.h"
using namespace Packets;
UINT GCCharSkill_MissedHandler::Execute( GCCharSkill_Missed* pPacket, Player* pPlayer )
{
	__ENTER_FUNCTION
		if(CGameProcedure::GetActiveProcedure() == (CGameProcedure*)CGameProcedure::s_pProcMain)
		{
			CObjectManager* pObjectManager = CObjectManager::GetMe();

			CObject* pObj = (CObject*)(pObjectManager->FindServerObject( pPacket->GetReceiverID() ));
			if ( pObj != NULL )
			{
				_DAMAGE_INFO infoDamage;
                infoDamage.m_nSkillID				= pPacket->GetSkillID();
				infoDamage.m_nTargetID				= pPacket->GetReceiverID();
				infoDamage.m_nSenderID				= pPacket->GetSenderID();
				infoDamage.m_nSenderLogicCount		= pPacket->GetSenderLogicCount();
				infoDamage.m_nType					= infoDamage.TYPE_SKILL_TEXT;
				infoDamage.m_nImpactID				= pPacket->GetFlag(); 				

				_LOGIC_EVENT logicEvent;
				logicEvent.Init(pPacket->GetSenderID(), pPacket->GetSenderLogicCount(), &infoDamage);

				SCommand_Object cmdTemp;
				cmdTemp.m_wID			= OC_LOGIC_EVENT;
				cmdTemp.m_apParam[0]	= (VOID*)(&logicEvent);
				pObj->PushCommand(&cmdTemp );

				pObj->PushDebugString("GCCharDirectImpact");
				pObj->SetMsgTime(CGameProcedure::s_pTimeSystem->GetTimeNow());
			}
		}

	return PACKET_EXE_CONTINUE ;
	__LEAVE_FUNCTION

		return PACKET_EXE_ERROR ;
}
