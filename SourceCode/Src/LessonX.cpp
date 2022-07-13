/////////////////////////////////////////////////////////////////////////////////
//
//
//
//
/////////////////////////////////////////////////////////////////////////////////
#include <Stdio.h>
#include "CommonClass.h"
#include "LessonX.h"

using namespace std;
////////////////////////////////////////////////////////////////////////////////
//
//
CGameMain		g_GameMain;	

//==============================================================================
//
// ����ĳ�������Ϊ��GameMainLoop����Ϊ��ѭ��������������ÿ֡ˢ����Ļͼ��֮�󣬶��ᱻ����һ�Ρ�

//==============================================================================
//
// ���캯��
CGameMain::CGameMain()
{
	m_iGameState			=	1;
	potato = new CSprite("potato");
	potato_speed_up=	0.f;
	potato_speed_down=	0.f;
	potato_speed_left=	0.f;
	potato_speed_right=	0.f;
}
//==============================================================================
//
// ��������
CGameMain::~CGameMain()
{
}

//==============================================================================
//
// ��Ϸ��ѭ�����˺���������ͣ�ĵ��ã�����ÿˢ��һ����Ļ���˺�����������һ��
// ���Դ�����Ϸ�Ŀ�ʼ�������С������ȸ���״̬. 
// ��������fDeltaTime : �ϴε��ñ��������˴ε��ñ�������ʱ��������λ����
void CGameMain::GameMainLoop( float	fDeltaTime )
{
	switch( GetGameState() )
	{
		// ��ʼ����Ϸ�������һ���������
	case 1:
		{
			GameInit();
			SetGameState(2); // ��ʼ��֮�󣬽���Ϸ״̬����Ϊ������
		}
		break;

		// ��Ϸ�����У����������Ϸ�߼�
	case 2:
		{
			// TODO �޸Ĵ˴���Ϸѭ�������������ȷ��Ϸ�߼�
			if( true )
			{
				GameRun( fDeltaTime );
			}
			else // ��Ϸ������������Ϸ���㺯����������Ϸ״̬�޸�Ϊ����״̬
			{				
				SetGameState(0);
				GameEnd();
			}
		}
		break;

		// ��Ϸ����/�ȴ����ո����ʼ
	case 0:
	default:
		break;
	};
}
//=============================================================================
//
// ÿ�ֿ�ʼǰ���г�ʼ���������һ���������
void CGameMain::GameInit()
{
	parallex_dirtmouth.add_player({ "potato", "cross_hair" });
	parallex_dirtmouth.add_scenery({
			"L12_dirtmouth_P1",
			"L12_dirtmouth_p2",
			"L13_dirtmouth_P1",
			"L13_dirtmouth_p2",
			"L14_dirtmouth_P1",
			"L14_dirtmouth_P2",
			"L15_dirtmouth_P1",
			"L15_dirtmouth_P2",
			"L15_dirtmouth_P3",
			"L15_dirtmouth_P4",
			"L16_dirtmouth_P1",
			"L16_dirtmouth_P2",
			"L17_dirtmouth_P1",
			"L17_dirtmouth_P2",
			"L18_dirtmouth_P1",
			"L18_dirtmouth_P2",
			"L19_dirtmouth_P1",
			"L19_dirtmouth_P2",
			"L20_dirtmouth_P1",
		});
	parallex_dirtmouth.add_camera_lock({
		"camera_lock_1",
		"camera_lock_2",
		"camera_lock_3",
		"camera_lock_4",
		});
	
	parallex_dirtmouth.set_screen_bondary(CSystem::GetScreenLeft(), CSystem::GetScreenRight(), CSystem::GetScreenTop(), CSystem::GetScreenBottom());

	parallex_dirtmouth.set_target_framing(0.f, 10.f);

	m_iGameState			=	2;
}
//=============================================================================
//
// ÿ����Ϸ������
void CGameMain::GameRun( float fDeltaTime )
{
	parallex_dirtmouth.main_loop(fDeltaTime);
}
//=============================================================================
//
// ������Ϸ����
void CGameMain::GameEnd()
{
}
//==========================================================================
//
// ����ƶ�
// ���� fMouseX, fMouseY��Ϊ��굱ǰ����
void CGameMain::OnMouseMove( const float fMouseX, const float fMouseY )
{
	
}
//==========================================================================
//
// �����
// ���� iMouseType����갴��ֵ���� enum MouseTypes ����
// ���� fMouseX, fMouseY��Ϊ��굱ǰ����
void CGameMain::OnMouseClick( const int iMouseType, const float fMouseX, const float fMouseY )
{
	
}
//==========================================================================
//
// ��굯��
// ���� iMouseType����갴��ֵ���� enum MouseTypes ����
// ���� fMouseX, fMouseY��Ϊ��굱ǰ����
void CGameMain::OnMouseUp( const int iMouseType, const float fMouseX, const float fMouseY )
{
	
}
//==========================================================================
//
// ���̰���
// ���� iKey�������µļ���ֵ�� enum KeyCodes �궨��
// ���� iAltPress, iShiftPress��iCtrlPress�������ϵĹ��ܼ�Alt��Ctrl��Shift��ǰ�Ƿ�Ҳ���ڰ���״̬(0δ���£�1����)
void CGameMain::OnKeyDown( const int iKey, const bool bAltPress, const bool bShiftPress, const bool bCtrlPress )
{	
	switch(iKey)
	{
	case KEY_W:		
		potato_speed_up = -20.f;
		break;
	case KEY_A:
		potato_speed_left = -25.f;		
		break;
	case KEY_S:	
		potato_speed_down = 20.f;
		break;
	case KEY_D:
		potato_speed_right = 25.f;		
		break;
	case KEY_F:
		parallex_dirtmouth.set_target_framing(-22.f, 10.f);
		parallex_dirtmouth.force_target_framing();
		parallex_dirtmouth.set_target_framing(0.f, 10.f);
		break;
	}
	parallex_dirtmouth.set_player_linear_velocity(potato_speed_left + potato_speed_right, potato_speed_up + potato_speed_down);
}
//==========================================================================
//
// ���̵���
// ���� iKey������ļ���ֵ�� enum KeyCodes �궨��
void CGameMain::OnKeyUp( const int iKey )
{
	switch(iKey)
	{
	case KEY_W:		
		potato_speed_up = 0.f;
		break;
	case KEY_A:
		potato_speed_left = 0.f;		
		break;
	case KEY_S:	
		potato_speed_down = 0.f;
		break;
	case KEY_D:
		potato_speed_right = 0.f;		
		break;
	}	
	parallex_dirtmouth.set_player_linear_velocity( potato_speed_left + potato_speed_right, potato_speed_up + potato_speed_down);
}
//===========================================================================
//
// �����뾫����ײ
// ���� szSrcName��������ײ�ľ�������
// ���� szTarName������ײ�ľ�������
void CGameMain::OnSpriteColSprite( const char *szSrcName, const char *szTarName )
{
	
}
//===========================================================================
//
// ����������߽���ײ
// ���� szName����ײ���߽�ľ�������
// ���� iColSide����ײ���ı߽� 0 ��ߣ�1 �ұߣ�2 �ϱߣ�3 �±�
void CGameMain::OnSpriteColWorldLimit( const char *szName, const int iColSide )
{
	
}

