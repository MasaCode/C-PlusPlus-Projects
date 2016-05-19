#pragma once

#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <random>
#include <string>

#include "Cell.h"
#include "Snake.h"
#include "Ladder.h"

namespace SnakesAndLadders {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;


	const int PIC_SIZE = 40;
	const int MARGIN = 10 + PIC_SIZE;
	const int ROW_SIZE = 14;
	const int ARRAY_SIZE = 196;
	const int NUM_SNAKE = 5;
	const int NUM_LADDER = 5;


	/// <summary>
	/// Summary for MainForm
	/// </summary>
	public ref class MainForm : public System::Windows::Forms::Form
	{
	public:
		MainForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//

			_player1 = gcnew System::Windows::Forms::PictureBox();
			_player2 = gcnew System::Windows::Forms::PictureBox();
			_goal = gcnew System::Windows::Forms::PictureBox();
			_pics = gcnew array < System::Windows::Forms::PictureBox^>(ARRAY_SIZE);
			_gameGrid = gcnew array<Cell^>(ARRAY_SIZE);
			_snakes = gcnew array<Snake^>(NUM_SNAKE);
			_ladders = gcnew array<Ladder^>(NUM_LADDER);
			
			_snakeHead = gcnew array<String^>(NUM_SNAKE);
			_snakeTail = gcnew array<String^>(NUM_SNAKE);
			for (int i = 0; i < NUM_SNAKE; i++){
				_snakeHead[i] = "Pics/head" + (i + 1).ToString() + ".png";
				_snakeTail[i] = "Pics/tail" + (i + 1).ToString() + ".png";
			}



		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MainForm()
		{
			if (components)
			{
				delete components;
			}

			for (int i = 0; i < ARRAY_SIZE; i++){
				delete _pics[i];
				delete _gameGrid[i];
			}

		}
	private: 
		System::Windows::Forms::Button^  StartButton;
	private:
		array<System::Windows::Forms::PictureBox^>^ _pics;
		System::Windows::Forms::PictureBox^ _goal;
		System::Windows::Forms::PictureBox^ _player1;
		System::Windows::Forms::PictureBox^ _player2;
		array<Cell^>^ _gameGrid;
		array<Snake^>^ _snakes;
		array<Ladder^>^ _ladders;

		array<String^>^ _snakeHead;
		array<String^>^ _snakeTail;

		int _playerOneIndex = -1;
		int _playerTwoIndex = -1;
		System::Drawing::Point _firstPlayerOnePoint;
		System::Drawing::Point _firstPlayerTwoPoint;

		int _ternCounter = 1;

		bool isVisiblePlayerOne = true;
		bool isVisiblePlayerTwo = true;

		bool isReachedgoal = false;

	private: System::Windows::Forms::Button^  PlayButton;
	private: System::Windows::Forms::PictureBox^  dicePic;
	private: System::Windows::Forms::Label^  PlayerLabel;



	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->StartButton = (gcnew System::Windows::Forms::Button());
			this->PlayButton = (gcnew System::Windows::Forms::Button());
			this->dicePic = (gcnew System::Windows::Forms::PictureBox());
			this->PlayerLabel = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dicePic))->BeginInit();
			this->SuspendLayout();
			// 
			// StartButton
			// 
			this->StartButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->StartButton->Location = System::Drawing::Point(22, 521);
			this->StartButton->Name = L"StartButton";
			this->StartButton->Size = System::Drawing::Size(101, 85);
			this->StartButton->TabIndex = 0;
			this->StartButton->Text = L"Start";
			this->StartButton->UseVisualStyleBackColor = true;
			this->StartButton->Click += gcnew System::EventHandler(this, &MainForm::StartButton_Click);
			// 
			// PlayButton
			// 
			this->PlayButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->PlayButton->Location = System::Drawing::Point(22, 521);
			this->PlayButton->Name = L"PlayButton";
			this->PlayButton->Size = System::Drawing::Size(99, 85);
			this->PlayButton->TabIndex = 1;
			this->PlayButton->Text = L"Play";
			this->PlayButton->UseVisualStyleBackColor = true;
			this->PlayButton->Click += gcnew System::EventHandler(this, &MainForm::PlayButton_Click);
			// 
			// dicePic
			// 
			this->dicePic->Location = System::Drawing::Point(22, 400);
			this->dicePic->Name = L"dicePic";
			this->dicePic->Size = System::Drawing::Size(100, 94);
			this->dicePic->TabIndex = 2;
			this->dicePic->TabStop = false;
			// 
			// PlayerLabel
			// 
			this->PlayerLabel->AutoSize = true;
			this->PlayerLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->PlayerLabel->Location = System::Drawing::Point(4, 343);
			this->PlayerLabel->Name = L"PlayerLabel";
			this->PlayerLabel->Size = System::Drawing::Size(119, 32);
			this->PlayerLabel->TabIndex = 3;
			this->PlayerLabel->Text = L"Player1";
			this->PlayerLabel->Visible = false;
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(986, 740);
			this->Controls->Add(this->PlayerLabel);
			this->Controls->Add(this->dicePic);
			this->Controls->Add(this->PlayButton);
			this->Controls->Add(this->StartButton);
			this->Name = L"MainForm";
			this->Text = L"MainForm";
			this->Load += gcnew System::EventHandler(this, &MainForm::MainForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dicePic))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion


	private: System::Void initObjects(){
				 int i = 0;
				 std::mt19937 randomEngine;
				 randomEngine.seed(time(nullptr));
				 std::uniform_int_distribution<int> randTop(0, ARRAY_SIZE - ROW_SIZE*2);
				 std::uniform_int_distribution<int> randBottom(ROW_SIZE*2, ARRAY_SIZE);

				

				 //For snakes
				 while (i < NUM_SNAKE){
					 int topIndex = randTop(randomEngine);
					 int bottomIndex = randBottom(randomEngine);
					 if ((topIndex ) / ROW_SIZE > (bottomIndex) / ROW_SIZE){
						 if (_gameGrid[topIndex]->getSymbol() == 'E' && _gameGrid[bottomIndex]->getSymbol() == 'E'){
							 //Make sure call setString function before call init function
							 _snakes[i] = gcnew Snake();
							 _snakes[i]->setString(_snakeHead[i%3], _snakeTail[i%3]);
							 _snakes[i]->init(_gameGrid[topIndex]->getPoint(), _gameGrid[bottomIndex]->getPoint(),
												topIndex,bottomIndex,PIC_SIZE);


							 _gameGrid[topIndex]->setSymbol('H');
							 _gameGrid[bottomIndex]->setSymbol('T');

							 i++;
						 }
					 }
				 }

				 i = 0;
				 //For ladders
				 while (i < NUM_LADDER){
					 int topIndex = randTop(randomEngine);
					 int bottomIndex = randBottom(randomEngine);
					 if ((topIndex) / ROW_SIZE >(bottomIndex) / ROW_SIZE){
						 if (_gameGrid[topIndex]->getSymbol() == 'E' && _gameGrid[bottomIndex]->getSymbol() == 'E'){
							 //Make sure call setString function before call init function
							 _ladders[i] = gcnew Ladder();
							 _ladders[i]->init(_gameGrid[topIndex]->getPoint(), _gameGrid[bottomIndex]->getPoint(),
								 topIndex, bottomIndex, PIC_SIZE);


							 _gameGrid[topIndex]->setSymbol('A'); // Above
							 _gameGrid[bottomIndex]->setSymbol('B'); //Below

							 i++;
						 }
					 }
				 }


	}

	private: System::Void PrintGrid(){
				 std::string buffer = "";
				 for (int i = 0; i < ARRAY_SIZE; i++){
					 buffer = buffer + " " +   _gameGrid[i]->getSymbol();
					 if ((i + 1) % ROW_SIZE == 0){
						 buffer = buffer +  "\n";
					 }
				 }

				 String^ text = gcnew String(buffer.c_str());
				 MessageBox::Show(text);
	}

	private: System::Void MainForm_Load(System::Object^  sender, System::EventArgs^  e) {
		int x = MARGIN*2, y = MARGIN/2;
			for (int i = 0; i < ARRAY_SIZE; i++){
				_pics[i] = gcnew System::Windows::Forms::PictureBox();
				_pics[i]->Name = i.ToString();
				_pics[i]->Location = System::Drawing::Point(x, y);
				_pics[i]->Size = System::Drawing::Size(PIC_SIZE, PIC_SIZE);
				_pics[i]->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
				_pics[i]->Image = gcnew Bitmap("Pics/floor.png");
				this->Controls->Add(this->_pics[i]);

				if (((i + 1) % ROW_SIZE) == 0){
					y += PIC_SIZE;
					x = MARGIN + MARGIN;
				}
				else{
					x += PIC_SIZE;
				}
			}


			int gridCounter = 0;
			for (int i = ARRAY_SIZE-1; i >= 0; i--){

				if (((i)/ ROW_SIZE) % 2 == 1 || (i +1) == ARRAY_SIZE){
					int pos = ROW_SIZE - (i + 1) % ROW_SIZE;
					int rightSide = ((i / ROW_SIZE) + 1) * ROW_SIZE;

					if ((i + 1) % ROW_SIZE == 0){
						//MessageBox::Show("if(1) , if(rowsize) , i = " + i.ToString() + "\n" + " current position " + gridCounter.ToString() + ", pics " + (i - ROW_SIZE + 1).ToString());
						_gameGrid[gridCounter] = gcnew Cell(_pics[i - ROW_SIZE + 1]->Location, 'E',i - ROW_SIZE + 1);
					}
					else{
						//MessageBox::Show("if(1), i = " + i.ToString() + "\n" + " current position " + gridCounter.ToString() + ", pics " + (rightSide - ROW_SIZE + pos).ToString());
						_gameGrid[gridCounter] = gcnew Cell(_pics[rightSide - ROW_SIZE + pos]->Location, 'E', rightSide - ROW_SIZE + pos);
					}
					gridCounter++;
				}
				else{
					//MessageBox::Show("if(0), i = " + i.ToString() + "\n" + " Current position " + gridCounter.ToString() + ", pics " + i.ToString());
					_gameGrid[gridCounter] = gcnew Cell(_pics[i]->Location, 'E',i);
					gridCounter++;
				}
			}


			_goal = gcnew System::Windows::Forms::PictureBox();
			_goal->Name = "goal";
			_goal->Location = System::Drawing::Point(_pics[0]->Location.X - PIC_SIZE, _pics[0]->Location.Y);
			_goal->Size = System::Drawing::Size(PIC_SIZE, PIC_SIZE);
			_goal->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			_goal->Image = gcnew Bitmap("Pics/goalicon.png");
			this->Controls->Add(this->_goal);



			initObjects();

			PlayButton->Enabled = false;
			PlayButton->Visible = false;

	}

	private: System::Void drawPlayers(System::Windows::Forms::PictureBox^ _player, System::String^ path, System::Drawing::Point point){
				 //Make Sure if you wanna draw on the gameGrid, you need to remove the picturebox.
				 _player->Location = point;
				 _player->Size = System::Drawing::Size(PIC_SIZE, PIC_SIZE);
				 _player->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
				 _player->Image = gcnew Bitmap(path);
				 this->Controls->Add(_player);
	}

	private: System::Void drawDice(int number){
				 switch (number){
				 case 1:
					 this->dicePic->Image = gcnew Bitmap("Pics/one.png");
					 break;
				 case 2:
					 this->dicePic->Image = gcnew Bitmap("Pics/two.png");
					 break;
				 case 3:
					 this->dicePic->Image = gcnew Bitmap("Pics/three.png");
					 break;
				 case 4:
					 this->dicePic->Image = gcnew Bitmap("Pics/four.png");
					 break;
				 case 5:
					 this->dicePic->Image = gcnew Bitmap("Pics/five.png");
					 break;
				 case 6:
					 this->dicePic->Image = gcnew Bitmap("Pics/six.png");
					 break;
				 default:
					 MessageBox::Show("WOOOW its wrong number");
					 break;
				 }
	}

	private: System::Void StartButton_Click(System::Object^  sender, System::EventArgs^  e) {

				 _firstPlayerOnePoint = System::Drawing::Point(-PIC_SIZE + _gameGrid[0]->getX(), _gameGrid[0]->getY());
				 drawPlayers(_player1, "Pics/playerOnebase.png",_firstPlayerOnePoint);

				 _firstPlayerTwoPoint = System::Drawing::Point(-PIC_SIZE + _gameGrid[0]->getX(), -PIC_SIZE + _gameGrid[0]->getY());
				 drawPlayers(_player2, "Pics/playerTwobase.png", _firstPlayerTwoPoint);

				 
				 for (int i = 0; i < NUM_SNAKE; i++){
					 //MessageBox::Show("SnakeHead : (" + _snakes[i]->getTopLocation().X.ToString() + " , " + _snakes[i]->getTopLocation().Y.ToString() + ") \n"
					 // + "SnakeTail : (" + _snakes[i]->getBottomLocation().X.ToString() + " , " + _snakes[i]->getBottomLocation().Y.ToString() + ")");
					 //this->Controls->Remove(_pics[_gameGrid[_snakes[i]->getTopIndex()]->getIndex()]);
					 //this->Controls->Remove(_pics[_gameGrid[_snakes[i]->getBottomIndex()]->getIndex()]);
					 _pics[_gameGrid[_snakes[i]->getTopIndex()]->getIndex()]->Visible = false;
					 _pics[_gameGrid[_snakes[i]->getBottomIndex()]->getIndex()]->Visible = false;

					 this->Controls->Add(_snakes[i]->drawTop());
					 this->Controls->Add(_snakes[i]->drawBottom());
				 }

				 for (int i = 0; i < NUM_LADDER; i++){

					 //this->Controls->Remove(_pics[_gameGrid[_ladders[i]->getTopIndex()]->getIndex()]);
					 //this->Controls->Remove(_pics[_gameGrid[_ladders[i]->getBottomIndex()]->getIndex()]);

					 _pics[_gameGrid[_ladders[i]->getTopIndex()]->getIndex()]->Visible = false;
					 _pics[_gameGrid[_ladders[i]->getBottomIndex()]->getIndex()]->Visible = false;

					 this->Controls->Add(_ladders[i]->drawTop());
					 this->Controls->Add(_ladders[i]->drawBottom());
				 }



				 StartButton->Enabled = false;
				 StartButton->Visible = false;

				 PlayButton->Enabled = true;
				 PlayButton->Visible = true;


				 PlayerLabel->Visible = true;
				
				 //drawing the dice image here
				 this->dicePic->Image = gcnew Bitmap("Pics/one.png");
				 this->dicePic->BorderStyle = BorderStyle::FixedSingle;

				 //PrintGrid();
				 //Remove pic box//
				 //this->Controls->Remove(this->_pics[_gameGrid[tempIndex]->getIndex()]);

	}



	private: System::Void PlayerOneMovement(int number){
				 // This is for drawing the floor and increasing the playerOneIndex.
				 if (_playerOneIndex != -1){
					 if (_gameGrid[_playerOneIndex]->getSymbol() == 'E' && isVisiblePlayerTwo){
						 _pics[_gameGrid[_playerOneIndex]->getIndex()]->Visible = true;
					 }
					 _playerOneIndex += number;
				 }
				 else{
					 _playerOneIndex = number;
					 _player1->Image = gcnew Bitmap("Pics/playerOne.png");
				 }
					

				 //From here I need to think about how to cllide with snakes&ladders and other player.

				 if (_playerOneIndex > ARRAY_SIZE && !isReachedgoal){
					 _player1->Location = _firstPlayerOnePoint;
					 _player1->Image = gcnew Bitmap("Pics/playerOnebase.png");
					 _playerOneIndex = -1;
				 }else if (_playerOneIndex == ARRAY_SIZE){
					 //Player1 reached the goal
					 if (isReachedgoal){
						 _player1->Location = _goal->Location;
						 _player1->Image = gcnew Bitmap("Pics/playersgoal.png");
						 MessageBox::Show("Both of player win!!!!!!");
						 exit(0);

					 }
					 else{
						 isReachedgoal = true;
						 _goal->Visible = false;
						 _player1->Location = _goal->Location;
						 _player1->Image = gcnew Bitmap("Pics/playerOnegoal.png");

					 }

				 }else{
					 //Check if the other player is already reached the goal
					 if (isReachedgoal){
						 MessageBox::Show("Player2 win!!!!!!");
						 exit(0);
					 }

					 //After icrease palyerOneIndex, get the symbol and check collision
					 char symbol = _gameGrid[_playerOneIndex]->getSymbol();
					 
					 if (symbol == 'H'){
						 for (int i = 0; i < NUM_SNAKE; i++){
							 if (_snakes[i]->getTopIndex() == _playerOneIndex){

								 _player1->Location = _snakes[i]->getBottomLocation();
								 _playerOneIndex = _snakes[i]->getBottomIndex();

							 }
						 }
					 }
					 else if (symbol == 'B'){
						 for (int i = 0; i < NUM_LADDER; i++){
							 if (_ladders[i]->getBottomIndex() == _playerOneIndex){

								 _player1->Location = _ladders[i]->getTopLocation();
								 _playerOneIndex = _ladders[i]->getTopIndex();

							 }
						 }
					 }
					 else{

						 _player1->Location = _gameGrid[_playerOneIndex]->getPoint();
						 _pics[_gameGrid[_playerOneIndex]->getIndex()]->Visible = false;

					 }

					 //If two player is colliding
					 if (_playerOneIndex == _playerTwoIndex){
						 isVisiblePlayerOne = false;
						 isVisiblePlayerTwo = false;

						 _player1->Image = gcnew Bitmap("Pics/players.png");
					 }
					 else if (!isVisiblePlayerOne){
						 _player1->Image = gcnew Bitmap("Pics/playerOne.png");
						 isVisiblePlayerOne = true;
					 }


				}
	}

	private: System::Void PlayerTwoMovement(int number){
				 // This is for drawing the floor and increasing the playerOneIndex.
				 if (_playerTwoIndex != -1){
					 if (_gameGrid[_playerTwoIndex]->getSymbol() == 'E' && isVisiblePlayerOne){
						 _pics[_gameGrid[_playerTwoIndex]->getIndex()]->Visible = true;
					 }
					 _playerTwoIndex += number;
				 }
				 else{
					 _playerTwoIndex = number;
					 _player2->Image = gcnew Bitmap("Pics/playerTwo.png");
				 }


				 //From here I need to think about how to cllide with snakes&ladders.
				 if (_playerTwoIndex > ARRAY_SIZE && !isReachedgoal){
					 _player2->Location = _firstPlayerTwoPoint;
					 _player2->Image = gcnew Bitmap("Pics/playerTwobase.png");
					 _playerTwoIndex = -1;
				 }
				 else if (_playerTwoIndex == ARRAY_SIZE){
					 _player2->Location = _goal->Location;
					 if (isReachedgoal){
						 MessageBox::Show("Both of player win!!!!!!");
						 exit(0);
					 }
					 else{
						 isReachedgoal = true;
						 _player2->Image = gcnew Bitmap("Pics/playerTwogoal.png");
						 _goal->Visible = false;
					 }
				 }else{
					 //Check if the other player is already reached the goal
					 if (isReachedgoal){
						 MessageBox::Show("Player1 win!!!!!!");
						 exit(0);
					 }


					 //After icrease palyerOneIndex, get the symbol and check collision
					 char symbol = _gameGrid[_playerTwoIndex]->getSymbol();

					 if (symbol == 'H'){
						 for (int i = 0; i < NUM_SNAKE; i++){
							 if (_snakes[i]->getTopIndex() == _playerTwoIndex){
								 _player2->Location = _snakes[i]->getBottomLocation();
								 _playerTwoIndex = _snakes[i]->getBottomIndex();
							 }
						 }

					 }
					 else if (symbol == 'B'){
						 for (int i = 0; i < NUM_LADDER; i++){
							 if (_ladders[i]->getBottomIndex() == _playerTwoIndex){
								 _player2->Location = _ladders[i]->getTopLocation();
								 _playerTwoIndex = _ladders[i]->getTopIndex();
							 }
						 }

					 }
					 else{


						 _player2->Location = _gameGrid[_playerTwoIndex]->getPoint();
						 _pics[_gameGrid[_playerTwoIndex]->getIndex()]->Visible = false;
					 }

					 //If two player is colliding
					 if (_playerOneIndex == _playerTwoIndex){
						 isVisiblePlayerOne = false;
						 isVisiblePlayerTwo = false;
						 _player1->Image = gcnew Bitmap("Pics/players.png");

					 }
					 else if (!isVisiblePlayerTwo){
						 _player1->Image = gcnew Bitmap("Pics/playerOne.png");
						 isVisiblePlayerTwo = true;

					 }

				 }
	}

	private: System::Void PlayButton_Click(System::Object^  sender, System::EventArgs^  e) {
				 std::mt19937 randomEngine;
				 randomEngine.seed(time(nullptr));
				 std::uniform_int_distribution<int> randDice(1,6);

				
				 srand(time(nullptr));
				
				 int number = (randDice(randomEngine) * rand()) % 6 + 1;

				 drawDice(number);
				 if ((_ternCounter % 2) == 1){ // Player1
					 PlayerOneMovement(number);

					 PlayerLabel->Text = "Player2";

				 }
				 else{ //Player2
					 PlayerTwoMovement(number);
					 PlayerLabel->Text = "Player1";
				 }

				 _ternCounter++;

	}
};
}
