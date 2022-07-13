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
// 大体的程序流程为：GameMainLoop函数为主循环函数，在引擎每帧刷新屏幕图像之后，都会被调用一次。

//==============================================================================
//
// 构造函数
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
// 析构函数
CGameMain::~CGameMain()
{
}

//==============================================================================
//
// 游戏主循环，此函数将被不停的调用，引擎每刷新一次屏幕，此函数即被调用一次
// 用以处理游戏的开始、进行中、结束等各种状态. 
// 函数参数fDeltaTime : 上次调用本函数到此次调用本函数的时间间隔，单位：秒
void CGameMain::GameMainLoop( float	fDeltaTime )
{
	switch( GetGameState() )
	{
		// 初始化游戏，清空上一局相关数据
	case 1:
		{
			GameInit();
			SetGameState(2); // 初始化之后，将游戏状态设置为进行中
		}
		break;

		// 游戏进行中，处理各种游戏逻辑
	case 2:
		{
			// TODO 修改此处游戏循环条件，完成正确游戏逻辑
			if( true )
			{
				GameRun( fDeltaTime );
			}
			else // 游戏结束。调用游戏结算函数，并把游戏状态修改为结束状态
			{				
				SetGameState(0);
				GameEnd();
			}
		}
		break;

		// 游戏结束/等待按空格键开始
	case 0:
	default:
		break;
	};
}
//=============================================================================
//
// 每局开始前进行初始化，清空上一局相关数据
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
// 每局游戏进行中
void CGameMain::GameRun( float fDeltaTime )
{
	parallex_dirtmouth.main_loop(fDeltaTime);
}
//=============================================================================
//
// 本局游戏结束
void CGameMain::GameEnd()
{
}
//==========================================================================
//
// 鼠标移动
// 参数 fMouseX, fMouseY：为鼠标当前坐标
void CGameMain::OnMouseMove( const float fMouseX, const float fMouseY )
{
	
}
//==========================================================================
//
// 鼠标点击
// 参数 iMouseType：鼠标按键值，见 enum MouseTypes 定义
// 参数 fMouseX, fMouseY：为鼠标当前坐标
void CGameMain::OnMouseClick( const int iMouseType, const float fMouseX, const float fMouseY )
{
	
}
//==========================================================================
//
// 鼠标弹起
// 参数 iMouseType：鼠标按键值，见 enum MouseTypes 定义
// 参数 fMouseX, fMouseY：为鼠标当前坐标
void CGameMain::OnMouseUp( const int iMouseType, const float fMouseX, const float fMouseY )
{
	
}
//==========================================================================
//
// 键盘按下
// 参数 iKey：被按下的键，值见 enum KeyCodes 宏定义
// 参数 iAltPress, iShiftPress，iCtrlPress：键盘上的功能键Alt，Ctrl，Shift当前是否也处于按下状态(0未按下，1按下)
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
// 键盘弹起
// 参数 iKey：弹起的键，值见 enum KeyCodes 宏定义
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
// 精灵与精灵碰撞
// 参数 szSrcName：发起碰撞的精灵名字
// 参数 szTarName：被碰撞的精灵名字
void CGameMain::OnSpriteColSprite( const char *szSrcName, const char *szTarName )
{
	
}
//===========================================================================
//
// 精灵与世界边界碰撞
// 参数 szName：碰撞到边界的精灵名字
// 参数 iColSide：碰撞到的边界 0 左边，1 右边，2 上边，3 下边
void CGameMain::OnSpriteColWorldLimit( const char *szName, const int iColSide )
{
	
}

