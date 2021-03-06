//------------------------------------------------------------------------
// GameTest.cpp
//------------------------------------------------------------------------
#include "stdafx.h"
//------------------------------------------------------------------------
#include <windows.h> 
#include <math.h>  
//------------------------------------------------------------------------
#include "app\app.h"
//------------------------------------------------------------------------


float HVelocity;
bool lastDirection = false;
//------------------------------------------------------------------------
// Example data....
//------------------------------------------------------------------------
//CSimpleSprite *testSprite;
//CSimpleSprite *testSprite2;
CSimpleSprite *Boxathan;
enum
{
	ANIM_IDLE,
	ANIM_RIGHT,
	ANIM_JUMP,
	ANIM_FALL,
	ANIM_WALL,
};
//------------------------------------------------------------------------

//------------------------------------------------------------------------
// Called before first update. Do any initial setup here.
//------------------------------------------------------------------------
void Init()
{
	//------------------------------------------------------------------------
	// Example Sprite Code....

	/*testSprite2 = App::CreateSprite(".\\TestData\\Ships.bmp", 2, 12);
	testSprite2->SetPosition(400.0f, 400.0f);	
	testSprite2->SetFrame(2);
	testSprite2->SetScale(1.0f);*/

	Boxathan = App::CreateSprite(".\\TestData\\BoxathanSprites.bmp", 12, 3);
	Boxathan->SetPosition(400.0f, 400.0f);
	float speed = 1.0f / 15.0f;
	Boxathan->CreateAnimation(ANIM_RIGHT, speed, { 0,1,2,3,4,5,6,7,8,9,10,11 });
	Boxathan->CreateAnimation(ANIM_IDLE, speed, { 12,13,14,15,16,17,18,19,20,21,22 });
	Boxathan->CreateAnimation(ANIM_JUMP, speed, { 23 });
	Boxathan->CreateAnimation(ANIM_FALL, speed, { 24 });
	Boxathan->CreateAnimation(ANIM_WALL, speed, { 25,25,26,27,28,29 });
	Boxathan->SetScale(2.0f);
	//------------------------------------------------------------------------
}

//------------------------------------------------------------------------
// Update your simulation here. deltaTime is the elapsed time since the last update in ms.
// This will be called at no greater frequency than the value of APP_MAX_FRAME_RATE
//------------------------------------------------------------------------
void Update(float deltaTime)
{
	//------------------------------------------------------------------------
	// Example Sprite Code....
	// Flip Sprite
	Boxathan->FlipSprite(lastDirection);
	HVelocity = App::GetController().GetLeftThumbStickX();

	if (HVelocity != 0.f)
	{
		lastDirection = HVelocity < 0.f ? true : false;
	}

	Boxathan->Update(deltaTime);
	if (HVelocity > 0.5f)
	{
		Boxathan->SetAnimation(ANIM_RIGHT);
		float x, y;
		Boxathan->GetPosition(x, y);
		x += 1.0f;
		Boxathan->SetPosition(x, y);
	}
	if (HVelocity < -0.5f)
	{
		Boxathan->SetAnimation(ANIM_RIGHT);
		float x, y;
		Boxathan->GetPosition(x, y);
		x -= 1.0f;
		Boxathan->SetPosition(x, y);
	}

	//------------------------------------------------------------------------
	// Sample Sound.
	//------------------------------------------------------------------------
	if (App::GetController().CheckButton(XINPUT_GAMEPAD_B, true))
	{
		App::PlaySound(".\\TestData\\Test.wav");
	}
}

//------------------------------------------------------------------------
// Add your display calls here (DrawLine,Print, DrawSprite.) 
// See App.h 
//------------------------------------------------------------------------
void Render()
{	

	//------------------------------------------------------------------------
	// Example Line Drawing.
	//------------------------------------------------------------------------
	/*static float a = 0.0f;
	float r = 1.0f;
	float g = 1.0f;
	float b = 1.0f;
	a += 0.1f;
	for (int i = 0; i < 20; i++)
	{

		float sx = 200 + sinf(a + i * 0.1f)*60.0f;
		float sy = 200 + cosf(a + i * 0.1f)*60.0f;
		float ex = 700 - sinf(a + i * 0.1f)*60.0f;
		float ey = 700 - cosf(a + i * 0.1f)*60.0f;
		g = (float)i / 20.0f;
		b = (float)i / 20.0f;
		App::DrawLine(sx, sy, ex, ey,r,g,b);
	}*/

	//------------------------------------------------------------------------
	// Example Sprite Code....
	//testSprite->Draw();
	//testSprite2->Draw();
	Boxathan->Draw();
	//------------------------------------------------------------------------

	//------------------------------------------------------------------------
	// Example Text.
	//------------------------------------------------------------------------
	//App::Print(0, 300, std::to_string(HVelocity).c_str());

}
//------------------------------------------------------------------------
// Add your shutdown code here. Called when the APP_QUIT_KEY is pressed.
// Just before the app exits.
//------------------------------------------------------------------------
void Shutdown()
{	
	//------------------------------------------------------------------------
	// Example Sprite Code....
	delete Boxathan;
	//------------------------------------------------------------------------
}