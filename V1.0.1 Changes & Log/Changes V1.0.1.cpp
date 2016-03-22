// FirstAssignment(Final).cpp: A program using the TL-Engine

#include <TL-Engine.h>	// TL-Engine include file and namespace
using namespace tle;

void main()
{
	// Create a 3D engine (using TLX engine here) and open a window for it
	I3DEngine* myEngine = New3DEngine( kTLX );
	myEngine->StartWindowed();

	// Add default folder for meshes and other media
	myEngine->AddMediaFolder( "D:\\Uni Work\\Programming Software\\TL-Engine\\TL-Engine\\Media" );

	/**** Set up your scene here ****/

	IMesh* floorMesh = myEngine->LoadMesh("floor.x");
	IMesh* sphereMesh = myEngine->LoadMesh("ball.x");

	IModel* floor = floorMesh->CreateModel(0, 0, 0);
	IModel* sphere1 = sphereMesh->CreateModel(-50, 20, 50);
	IModel* sphere2 = sphereMesh->CreateModel(50, 20, 50);
	IModel* sphere3 = sphereMesh->CreateModel(0, 20, 100);
	IModel* sphere4 = sphereMesh->CreateModel(0, 20, 0);

	sphere1->SetSkin("blue.png");
	sphere2->SetSkin("violet.png");
	sphere3->SetSkin("indigo.png");
	sphere4->SetSkin("fawn.png");

	ICamera* myCamera = myEngine->CreateCamera(kManual, 0, 120, -200);
	myCamera->RotateX(20);

	float sphere1MovementX = 0;
	float sphere2MovementX = 0;
	float sphere3MovementX = 0;
	float sphere4MovementX = 0;

	float sphere1MovementZ = 0;
	float sphere2MovementZ = 0;
	float sphere3MovementZ = 0;
	float sphere4MovementZ = 0;

	float sphere1RotateX = 0;
	float sphere2RotateX = 0;
	float sphere3RotateX = 0;
	float sphere4RotateX = 0;

	float sphere1RotateZ = 0;
	float sphere2RotateZ = 0;
	float sphere3RotateZ = 0;
	float sphere4RotateZ = 0;

	float sphereRotateSpeed = 2.0f;
	
	float kGameSpeed = 0.01f;

	float sphereSpeed = 0.5f;

	float sphereMouseMovement = 1.0f;

	float skinChange1 = 1; 
	float skinChange2 = 2;
	float skinChange3 = 3;
	float skinChange4 = 4;

	float gameSpeedDivide = 2;

	float yAxisUpperLimit = 40;
	float yAxisLowerLimit = 20;

	float sphereSpeedMax = 5;
	float sphereSpeedMin = 0.5;
	float mouseWheelForward = 1.0;
	float mouseWheelBack = 1.0;
	float sphereSpeedInc = 1.0;
	float sphereSpeedDec = 1.0;
	float sphereRotateSpeedInc = 0.5;
	float sphereRotateSpeedDec = 0.5;

	int skinChange = 1;
	int bottomLeft = 0;
	int topLeft = 50;
	int topRight = 100;
	int bottomRight = 50;
	
	//---Once the P key is hit, it will change to true and pause the whole game
	//---It starts of with the mouse showing, once the Tab key is hit the mouse disappears
	//---Once the R key is hit, it will change the direction and rotation of all four balls
	bool paused = false;
	bool mouseToggle = false;
	bool reverse = false;

	// The main game loop, repeat until engine is stopped
	while (myEngine->IsRunning())
	{
		//---If the P key is hit, everything inside the if statement will stop moving
		if (myEngine->KeyHit(Key_P))
		{
			paused = !paused;
		}
		if (paused == false)
		{
		// Draw the scene
		myEngine->DrawScene();

		//---An if statement for each direction in which the spheres are moving
		//---Each direction moves along the X ans Z simultaneously
		//---As with the pause boolean, the reverse boolean works similarily
		//---Everything inside the if statement when the R key is hit will change the direction
		//---The four balls change direction and when pressing E, the direction of the sphere texture change also reverses
		if (myEngine->KeyHit(Key_R))
		{
			reverse = !reverse;
		}
		if (!reverse)
		{
			if (sphere1->GetZ() <= bottomLeft) //BottomLeft
			{
				sphere1MovementX = -sphereSpeed * kGameSpeed;
				sphere1MovementZ = sphereSpeed * kGameSpeed;

				sphere1RotateX = (sphereRotateSpeed + sphereSpeed);
				sphere1RotateZ = (sphereRotateSpeed + sphereSpeed);
			}
			if (sphere1->GetX() <= -topLeft) //TopLeft
			{
				sphere1MovementX = sphereSpeed * kGameSpeed;
				sphere1MovementZ = sphereSpeed * kGameSpeed;

				sphere1RotateX = (sphereRotateSpeed + sphereSpeed);
				sphere1RotateZ = (-sphereRotateSpeed + sphereSpeed);
			}
			if (sphere1->GetZ() >= topRight) //TopRight
			{
				sphere1MovementX = sphereSpeed * kGameSpeed;
				sphere1MovementZ = -sphereSpeed * kGameSpeed;

				sphere1RotateX = (-sphereRotateSpeed + sphereSpeed);
				sphere1RotateZ = (-sphereRotateSpeed + sphereSpeed);
			}
			if (sphere1->GetX() >= bottomRight) //BottomRight
			{
				sphere1MovementX = -sphereSpeed * kGameSpeed;
				sphere1MovementZ = -sphereSpeed * kGameSpeed;

				sphere1RotateX = (-sphereRotateSpeed + sphereSpeed);
				sphere1RotateZ = (sphereRotateSpeed + sphereSpeed);
			}

			if (sphere2->GetZ() <= bottomLeft) //BottomLeft
			{
				sphere2MovementX = -sphereSpeed * kGameSpeed;
				sphere2MovementZ = sphereSpeed * kGameSpeed;

				sphere2RotateX = (sphereRotateSpeed + sphereSpeed);
				sphere2RotateZ = (sphereRotateSpeed + sphereSpeed);
			}
			if (sphere2->GetX() <= -topLeft) //TopLeft
			{
				sphere2MovementX = sphereSpeed * kGameSpeed;
				sphere2MovementZ = sphereSpeed * kGameSpeed;

				sphere2RotateX = (sphereRotateSpeed + sphereSpeed);
				sphere2RotateZ = (-sphereRotateSpeed + sphereSpeed);
			}
			if (sphere2->GetZ() >= topRight) //TopRight
			{
				sphere2MovementX = sphereSpeed * kGameSpeed;
				sphere2MovementZ = -sphereSpeed * kGameSpeed;

				sphere2RotateX = (-sphereRotateSpeed + sphereSpeed);
				sphere2RotateZ = (-sphereRotateSpeed + sphereSpeed);
			}
			if (sphere2->GetX() >= bottomRight) //BottomRight
			{
				sphere2MovementX = -sphereSpeed * kGameSpeed;
				sphere2MovementZ = -sphereSpeed * kGameSpeed;

				sphere2RotateX = (-sphereRotateSpeed + sphereSpeed);
				sphere2RotateZ = (sphereRotateSpeed + sphereSpeed);
			}

			if (sphere3->GetZ() <= bottomLeft) //BottomLeft
			{
				sphere3MovementX = -sphereSpeed * kGameSpeed;
				sphere3MovementZ = sphereSpeed * kGameSpeed;

				sphere3RotateX = (sphereRotateSpeed + sphereSpeed);
				sphere3RotateZ = (sphereRotateSpeed + sphereSpeed);
			}
			if (sphere3->GetX() <= -topLeft) //TopLeft
			{
				sphere3MovementX = sphereSpeed * kGameSpeed;
				sphere3MovementZ = sphereSpeed * kGameSpeed;

				sphere3RotateX = (sphereRotateSpeed + sphereSpeed);
				sphere3RotateZ = (-sphereRotateSpeed + sphereSpeed);
			}
			if (sphere3->GetZ() >= topRight) //TopRight
			{
				sphere3MovementX = sphereSpeed * kGameSpeed;
				sphere3MovementZ = -sphereSpeed * kGameSpeed;

				sphere3RotateX = (-sphereRotateSpeed + sphereSpeed);
				sphere3RotateZ = (-sphereRotateSpeed + sphereSpeed);
			}
			if (sphere3->GetX() >= bottomRight) //BottomRight
			{
				sphere3MovementX = -sphereSpeed * kGameSpeed;
				sphere3MovementZ = -sphereSpeed * kGameSpeed;

				sphere3RotateX = (-sphereRotateSpeed + sphereSpeed);
				sphere3RotateZ = (sphereRotateSpeed + sphereSpeed);
			}

			if (sphere4->GetZ() <= bottomLeft) //BottomLeft
			{
				sphere4MovementX = -sphereSpeed * kGameSpeed;
				sphere4MovementZ = sphereSpeed * kGameSpeed;

				sphere4RotateX = (sphereRotateSpeed + sphereSpeed);
				sphere4RotateZ = (sphereRotateSpeed + sphereSpeed);
			}
			if (sphere4->GetX() <= -topLeft) //TopLeft
			{
				sphere4MovementX = sphereSpeed * kGameSpeed;
				sphere4MovementZ = sphereSpeed * kGameSpeed;

				sphere4RotateX = (sphereRotateSpeed + sphereSpeed);
				sphere4RotateZ = (-sphereRotateSpeed + sphereSpeed);
			}
			if (sphere4->GetZ() >= topRight) //TopRight
			{
				sphere4MovementX = sphereSpeed * kGameSpeed;
				sphere4MovementZ = -sphereSpeed * kGameSpeed;

				sphere4RotateX = (-sphereRotateSpeed + sphereSpeed);
				sphere4RotateZ = (-sphereRotateSpeed + sphereSpeed);
			}
			if (sphere4->GetX() >= bottomRight) //BottomRight
			{
				sphere4MovementX = -sphereSpeed * kGameSpeed;
				sphere4MovementZ = -sphereSpeed * kGameSpeed;

				sphere4RotateX = (-sphereRotateSpeed + sphereSpeed);
				sphere4RotateZ = (sphereRotateSpeed + sphereSpeed);
			}

			if (myEngine->KeyHit(Key_E))
			{
				if (skinChange == skinChange1)
				{
					sphere1->SetSkin("fawn.png");
					sphere2->SetSkin("indigo.png");
					sphere3->SetSkin("blue.png");
					sphere4->SetSkin("violet.png");
					skinChange++;
				}
				else if (skinChange == skinChange2)
				{
					sphere1->SetSkin("violet.png");
					sphere2->SetSkin("blue.png");
					sphere3->SetSkin("fawn.png");
					sphere4->SetSkin("indigo.png");
					skinChange++;
				}
				else if (skinChange == skinChange3)
				{
					sphere1->SetSkin("indigo.png");
					sphere2->SetSkin("fawn.png");
					sphere3->SetSkin("violet.png");
					sphere4->SetSkin("blue.png");
					skinChange++;
				}
				else if (skinChange == skinChange4)
				{
					sphere1->SetSkin("blue.png");
					sphere2->SetSkin("violet.png");
					sphere3->SetSkin("indigo.png");
					sphere4->SetSkin("fawn.png");
					skinChange = skinChange1;
				}
			}
		}
		else
		{
			if (sphere1->GetZ() <= bottomLeft) //BottomLeft
			{
				sphere1MovementX = sphereSpeed * kGameSpeed;
				sphere1MovementZ = sphereSpeed * kGameSpeed;

				sphere1RotateX = (sphereRotateSpeed + sphereSpeed);
				sphere1RotateZ = (-sphereRotateSpeed + sphereSpeed);
			}
			if (sphere1->GetX() <= -topLeft) //TopLeft
			{
				sphere1MovementX = sphereSpeed * kGameSpeed;
				sphere1MovementZ = -sphereSpeed * kGameSpeed;

				sphere1RotateX = (sphereRotateSpeed + sphereSpeed);
				sphere1RotateZ = (-sphereRotateSpeed + sphereSpeed);
			}
			if (sphere1->GetZ() >= topRight) //TopRight
			{
				sphere1MovementX = -sphereSpeed * kGameSpeed;
				sphere1MovementZ = -sphereSpeed * kGameSpeed;

				sphere1RotateX = (-sphereRotateSpeed + sphereSpeed);
				sphere1RotateZ = (sphereRotateSpeed + sphereSpeed);
			}
			if (sphere1->GetX() >= bottomRight) //BottomRight
			{
				sphere1MovementX = -sphereSpeed * kGameSpeed;
				sphere1MovementZ = sphereSpeed * kGameSpeed;

				sphere1RotateX = (sphereRotateSpeed + sphereSpeed);
				sphere1RotateZ = (sphereRotateSpeed + sphereSpeed);
			}

			if (sphere2->GetZ() <= bottomLeft) //BottomLeft
			{
				sphere2MovementX = sphereSpeed * kGameSpeed;
				sphere2MovementZ = sphereSpeed * kGameSpeed;

				sphere2RotateX = (sphereRotateSpeed + sphereSpeed);
				sphere2RotateZ = (-sphereRotateSpeed + sphereSpeed);
			}
			if (sphere2->GetX() <= -topLeft) //TopLeft
			{
				sphere2MovementX = sphereSpeed * kGameSpeed;
				sphere2MovementZ = -sphereSpeed * kGameSpeed;

				sphere2RotateX = (sphereRotateSpeed + sphereSpeed);
				sphere2RotateZ = (-sphereRotateSpeed + sphereSpeed);
			}
			if (sphere2->GetZ() >= topRight) //TopRight
			{
				sphere2MovementX = -sphereSpeed * kGameSpeed;
				sphere2MovementZ = -sphereSpeed * kGameSpeed;

				sphere2RotateX = (-sphereRotateSpeed + sphereSpeed);
				sphere2RotateZ = (sphereRotateSpeed + sphereSpeed);
			}
			if (sphere2->GetX() >= bottomRight) //BottomRight
			{
				sphere2MovementX = -sphereSpeed * kGameSpeed;
				sphere2MovementZ = sphereSpeed * kGameSpeed;

				sphere2RotateX = (sphereRotateSpeed + sphereSpeed);
				sphere2RotateZ = (sphereRotateSpeed + sphereSpeed);
			}

			if (sphere3->GetZ() <= bottomLeft) //BottomLeft
			{
				sphere3MovementX = sphereSpeed * kGameSpeed;
				sphere3MovementZ = sphereSpeed * kGameSpeed;

				sphere3RotateX = (sphereRotateSpeed + sphereSpeed);
				sphere3RotateZ = (-sphereRotateSpeed + sphereSpeed);
			}
			if (sphere3->GetX() <= -topLeft) //TopLeft
			{
				sphere3MovementX = sphereSpeed * kGameSpeed;
				sphere3MovementZ = -sphereSpeed * kGameSpeed;

				sphere3RotateX = (sphereRotateSpeed + sphereSpeed);
				sphere3RotateZ = (-sphereRotateSpeed + sphereSpeed);
			}
			if (sphere3->GetZ() >= topRight) //TopRight
			{
				sphere3MovementX = -sphereSpeed * kGameSpeed;
				sphere3MovementZ = -sphereSpeed * kGameSpeed;

				sphere3RotateX = (-sphereRotateSpeed + sphereSpeed);
				sphere3RotateZ = (sphereRotateSpeed + sphereSpeed);
			}
			if (sphere3->GetX() >= bottomRight) //BottomRight
			{
				sphere3MovementX = -sphereSpeed * kGameSpeed;
				sphere3MovementZ = sphereSpeed * kGameSpeed;

				sphere3RotateX = (sphereRotateSpeed + sphereSpeed);
				sphere3RotateZ = (sphereRotateSpeed + sphereSpeed);
			}

			if (sphere4->GetZ() <= bottomLeft) //BottomLeft
			{
				sphere4MovementX = sphereSpeed * kGameSpeed;
				sphere4MovementZ = sphereSpeed * kGameSpeed;

				sphere4RotateX = (sphereRotateSpeed + sphereSpeed);
				sphere4RotateZ = (-sphereRotateSpeed + sphereSpeed);
			}
			if (sphere4->GetX() <= -topLeft) //TopLeft
			{
				sphere4MovementX = sphereSpeed * kGameSpeed;
				sphere4MovementZ = -sphereSpeed * kGameSpeed;

				sphere4RotateX = (sphereRotateSpeed + sphereSpeed);
				sphere4RotateZ = (-sphereRotateSpeed + sphereSpeed);
			}
			if (sphere4->GetZ() >= topRight) //TopRight
			{
				sphere4MovementX = -sphereSpeed * kGameSpeed;
				sphere4MovementZ = -sphereSpeed * kGameSpeed;

				sphere4RotateX = (-sphereRotateSpeed + sphereSpeed);
				sphere4RotateZ = (sphereRotateSpeed + sphereSpeed);
			}
			if (sphere4->GetX() >= bottomRight) //BottomRight
			{
				sphere4MovementX = -sphereSpeed * kGameSpeed;
				sphere4MovementZ = sphereSpeed * kGameSpeed;

				sphere4RotateX = (sphereRotateSpeed + sphereSpeed);
				sphere4RotateZ = (sphereRotateSpeed + sphereSpeed);
			}

			if (myEngine->KeyHit(Key_E))
			{
				if (skinChange == skinChange1)
				{
					sphere1->SetSkin("indigo.png");
					sphere2->SetSkin("fawn.png");
					sphere3->SetSkin("violet.png");
					sphere4->SetSkin("blue.png");
					skinChange++;
				}
				else if (skinChange == skinChange2)
				{
					sphere1->SetSkin("violet.png");
					sphere2->SetSkin("blue.png");
					sphere3->SetSkin("fawn.png");
					sphere4->SetSkin("indigo.png");
					skinChange++;
				}
				else if (skinChange == skinChange3)
				{
					sphere1->SetSkin("fawn.png");
					sphere2->SetSkin("indigo.png");
					sphere3->SetSkin("blue.png");
					sphere4->SetSkin("violet.png");
					skinChange++;
				}
				else if (skinChange == skinChange4)
				{
					sphere1->SetSkin("blue.png");
					sphere2->SetSkin("violet.png");
					sphere3->SetSkin("indigo.png");
					sphere4->SetSkin("fawn.png");
					skinChange = skinChange1;
				}
			}
		}

		//---Moves both the spheres up and down on the Y Axis with the Up and Down Arrow Keys
		//---Both the spheres carry on rotating and travelling whilst moving up and down
		if (myEngine->KeyHeld(Key_Down))
		{
			sphere1->MoveY(-kGameSpeed / gameSpeedDivide);
			sphere2->MoveY(-kGameSpeed / gameSpeedDivide);
			sphere3->MoveY(-kGameSpeed / gameSpeedDivide);
			sphere4->MoveY(-kGameSpeed / gameSpeedDivide);
		}
		if (myEngine->KeyHeld(Key_Up))
		{
			sphere1->MoveY(kGameSpeed / gameSpeedDivide);
			sphere2->MoveY(kGameSpeed / gameSpeedDivide);
			sphere3->MoveY(kGameSpeed / gameSpeedDivide);
			sphere4->MoveY(kGameSpeed / gameSpeedDivide);
		}

		//---Stops the spheres from going 20 pixels above the floor
		//---Stops the sphere from going below the floor
		if (sphere1->GetY() < yAxisLowerLimit)
		{
			sphere1->SetY(yAxisLowerLimit);
		}
		else if (sphere1->GetY() > yAxisUpperLimit)
		{
			sphere1->SetY(yAxisUpperLimit);
		}
		if (sphere2->GetY() < yAxisLowerLimit)
		{
			sphere2->SetY(yAxisLowerLimit);
		}
		else if (sphere2->GetY() > yAxisUpperLimit)
		{
			sphere2->SetY(yAxisUpperLimit);
		}
		if (sphere3->GetY() < yAxisLowerLimit)
		{
			sphere3->SetY(yAxisLowerLimit);
		}
		else if (sphere3->GetY() > yAxisUpperLimit)
		{
			sphere3->SetY(yAxisUpperLimit);
		}
		if (sphere4->GetY() < yAxisLowerLimit)
		{
			sphere4->SetY(yAxisLowerLimit);
		}
		else if (sphere4->GetY() > yAxisUpperLimit)
		{
			sphere4->SetY(yAxisUpperLimit);
		}

		//---Increases/Decreases the speed of the spheres when the mouse wheel scrolled up/down
		//---Speed of the sphere is increased/decreased by 1
		sphereMouseMovement = myEngine->GetMouseWheelMovement();

		if (sphereMouseMovement == mouseWheelForward && sphereSpeed <= sphereSpeedMax)
		{
			sphereSpeed += sphereSpeedInc;
			sphereRotateSpeed += sphereRotateSpeedInc;
		}
		else if (sphereMouseMovement == -mouseWheelBack && sphereSpeed > sphereSpeedMin)
		{
			sphereSpeed -= sphereSpeedDec;
			sphereRotateSpeed -= sphereRotateSpeedDec;
		}

		//---When the tab key is pressed, it toggles the visiblity of the mouse cursor
		if (mouseToggle == true)
		{
			if (myEngine->KeyHit(Key_Tab))
			{
				myEngine->StopMouseCapture();
				mouseToggle = false;
			}
		}
		else
		{
			if (myEngine->KeyHit(Key_Tab))
			{
				myEngine->StartMouseCapture();
				mouseToggle = true;
			}
		}

		//---Declares the speed at which the spheres move on the X and Z axis instead of using magic numbers
		sphere1->MoveX(sphere1MovementX);
		sphere1->MoveZ(sphere1MovementZ);
		sphere2->MoveX(sphere2MovementX);
		sphere2->MoveZ(sphere2MovementZ);
		sphere3->MoveX(sphere3MovementX);
		sphere3->MoveZ(sphere3MovementZ);
		sphere4->MoveX(sphere4MovementX);
		sphere4->MoveZ(sphere4MovementZ);

		//---Checks to see if the spheres are at position 20 on the Y axis
		//---If they're not, they all stop rotating
		if (sphere1->GetY() <= yAxisLowerLimit)
		{
			sphere1->RotateX(sphere1RotateX * kGameSpeed);
			sphere1->RotateZ(sphere1RotateZ * kGameSpeed);
			sphere2->RotateX(sphere2RotateX * kGameSpeed);
			sphere2->RotateZ(sphere2RotateZ * kGameSpeed);
			sphere3->RotateX(sphere3RotateX * kGameSpeed);
			sphere3->RotateZ(sphere3RotateZ * kGameSpeed);
			sphere4->RotateX(sphere4RotateX * kGameSpeed);
			sphere4->RotateZ(sphere4RotateZ * kGameSpeed);
		}

		/**** Update your scene each frame here ****/
		}
		//---Quits the application when the Escape key is pressed
		if (myEngine->KeyHit(Key_Escape))
		{
			myEngine->Stop();
		}
	}

	// Delete the 3D engine now we are finished with it
	myEngine->Delete();
}