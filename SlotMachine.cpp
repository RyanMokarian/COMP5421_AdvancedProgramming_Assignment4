#include "SlotMachine.h"

void SlotMachine::run() {
    cout << "Welcome to 3-Reel Lucky Slot Machine Game!\n"
         << "Each reel will randomly display one of four shapes, each in 25 sizes.\n"
         << "To win 3 x bet Get 2 similar shapes AND 2 shapes with equal Scr Areas\n"
         << "To win 2x bet Get 3 similar shapes\n"
         << "To win 1 x bet Get (Middle) Scr Area > (Left + Right) Scr Areas\n"
         << "To win or lose nothing Get same Left and Right shapes\n"
         << "Otherwise, you lose your bet.\n"
         << "You start with 10 free slot tokens!\n" << endl;

    // first bet
    takeBet();

    // while user decides to begin\continue playing, show results then prompt next bet
    while ((bet > 0) && (tokens > 0)) {
        make_shapes();
        display();
        betMultiplier = calculatePayout();
        tokens = tokens + (bet * betMultiplier);
        winMessage();
        // Game Over message if player runs out of tokens
        if (tokens == 0) {
            cout << "You just ran out of tokens. Better luck next time!\n"
                 << "Game Over." << endl;
            break;
        }
        takeBet();
    }

}

// takes bet from user
void SlotMachine::takeBet() {
    cout << "How much would you like to bet (enter 0 to quit)? " << endl;
    cin >> bet;

    // ensures user does not bet more than available tokens
    while (bet > tokens) {
        cout << "You can't bet more than " << tokens << ", try again!\n\n" <<
             "How much would you like to bet (enter 0 to quit)? " << endl;
        cin >> bet;
    }

    // Game Over message if player chooses to cash out
    if (bet == 0) {
        cout << "Thank you for playing, come back soon!\n"
             << "Be sure you cash in your remaining " << tokens << " tokens at the bar!\n"
             << "Game Over." << endl;
    }

        // refuses negative bets
    else if (bet < 0) {
        cout << "No negative bets, try again!\n" << endl;
        takeBet();
    }

}

// runs make_shape 3 times to create 3 shapes
void SlotMachine::make_shapes() {
    make_shape(3);
}

// creates random shapes of random sizes
void SlotMachine::make_shape(int k) {

    srand((unsigned)time(0));

    for (int shapeNumber = 0; shapeNumber < k; shapeNumber++) {

        //generate random shape type [0-3]
        int n = (rand() % 4);

        // random width [1-25]
        int width = (rand() % 25) + 1;

        //random height [1-25]
        int height = (rand() % 25) + 1;

        // creates shape based on the random attributes
        if (n == 0) {
            this->reel[shapeNumber].reset(new Rhombus(width));
            // adjusts shape caption to match adjustment for even width value
            if (width % 2 == 1) {
                caption[shapeNumber] = "(Diamond, " + to_string(width) + ", " + to_string(width) + ")";
            }
            else {
                caption[shapeNumber] = "(Diamond, " + to_string(width + 1) + ", " + to_string(width + 1) + ")";
            }
        }

        else if
                (n == 1) {
            this->reel[shapeNumber].reset(new AcuteTriangle(width));
            // adjusts shape caption to match adjustment for even width value
            if (width % 2 == 1) {
                caption[shapeNumber] = "(Acute triangle, " + to_string(width) + ", " + to_string(int((width + 1) / 2)) + ")";
            }
            else {
                caption[shapeNumber] = "(Acute triangle, " + to_string(width + 1) + ", " + to_string(int((width / 2) + 1)) + ")";
            }
        }

        else if
                (n == 2) {
            this->reel[shapeNumber].reset(new RightTriangle(width));
            caption[shapeNumber] = "(Right triangle, " + to_string(width) + ", " + to_string(width) + ")";
        }

        else if (n == 3) {
            this->reel[shapeNumber].reset(new Rectangle(width, height));
            caption[shapeNumber] = "(Rectangle, " + to_string(width) + ", " + to_string(height) + ")";

        }
    }
}

// displays 3 shapes in boxes
void SlotMachine::display() {
    Grid box_0 = reel[0]->draw();
    Grid box_1 = reel[1]->draw();
    Grid box_2 = reel[2]->draw();

    // the box height is set to the largest of the shape heights
    int tableHeight = max(reel[0]->getBoxHeight(), reel[1]->getBoxHeight());
    tableHeight = max(tableHeight, reel[2]->getBoxHeight());

    // upper box perimeter
    cout << "+";
    for (int jTop = 0; jTop < reel[0]->getBoxWidth() + 2; jTop++)
    {
        cout << "-";
    }
    cout << "+";
    for (int jTop = 0; jTop < reel[1]->getBoxWidth() + 2; jTop++)
    {
        cout << "-";
    }
    cout << "+";
    for (int jTop = 0; jTop < reel[2]->getBoxWidth() + 2; jTop++)
    {
        cout << "-";
    }
    cout << "+" << endl;

    // side box perimeter and shape drawing
    for (int i = 0; i < tableHeight; i++) {
        for (int j0 = 0; j0 < reel[0]->getBoxWidth() + 2; j0++) {
            // prints outer-left box perimeter
            if (j0 == 0)
            {
                cout << "| ";
            }

            // prints 1st shape
            {
                if (i < box_0.size() && j0 < box_0[0].size())
                    cout << box_0[i][j0];
                else {
                    cout << " ";
                }
                // prints inner-right box perimeter beside 1st shape
                if (j0 == reel[0]->getBoxWidth())
                {
                    cout << "|";
                }
            }
        }

        // prints 2nd shape and 2nd shape right box perimeter
        for (int j1 = 0; j1 < reel[1]->getBoxWidth() + 2; j1++) {
            if (i < box_1.size() && j1 < box_1[0].size())
                cout << box_1[i][j1];
            else {
                cout << " ";
            }


            if (j1 == reel[1]->getBoxWidth())
            {
                cout << "|";
            }
        }

        // prints 3rd shape and 3rd shape right box perimeter
        for (int j2 = 0; j2 < reel[2]->getBoxWidth() + 2; j2++) {
            if (i < box_2.size() && j2 < box_2[0].size())
                cout << box_2[i][j2];
            else {
                cout << " ";
            }


            if (j2 == reel[2]->getBoxWidth())
            {
                cout << "|";
            }
        }
        cout << endl;
    }

    // bottom box perimeter
    cout << "+";
    for (int jBtm = 0; jBtm < reel[0]->getBoxWidth() + 2; jBtm++) {
        cout << "-";
    }
    cout << "+";
    for (int jBtm = 0; jBtm < reel[1]->getBoxWidth() + 2; jBtm++) {
        cout << "-";
    }
    cout << "+";
    for (int jBtm = 0; jBtm < reel[2]->getBoxWidth() + 2; jBtm++) {
        cout << "-";
    }
    cout << "+" << endl;

    // printout of shape names and sizes
    cout << caption[0] << "  " << caption[1] << "  " << caption[2] << endl;

}

// calculates winnings / losses
int SlotMachine::calculatePayout() {

    // checks if 2 screen areas are the same
    bool screenAreaMatch = false;
    if ((reel[0]->findScreenArea() == reel[1]->findScreenArea()) ||
        (reel[1]->findScreenArea() == reel[2]->findScreenArea()) ||
        (reel[1]->findScreenArea() == reel[2]->findScreenArea()))
    {
        screenAreaMatch = true;
    }

    // checks if middle screen area is largest
    bool greaterScreenMid = false;
    if (reel[1]->findScreenArea() > (reel[0]->findScreenArea() + reel[2]->findScreenArea())) {
        greaterScreenMid = true;
    }

    bool similar2Shapes = false;
    bool similar3Shapes = false;

    // checks if all 3 shapes are similar
    if ((typeid(*reel[0]).name() == typeid(*reel[1]).name()) &&
        (typeid(*reel[1]).name() == typeid(*reel[2]).name()))
    {
        similar3Shapes = true;
    }

    // checks if exactly 2 shapes are similar
    if (similar3Shapes == false)
    {
        if ((typeid(*reel[0]).name() == typeid(*reel[1]).name()) ||
            (typeid(*reel[1]).name() == typeid(*reel[2]).name()) ||
            (typeid(*reel[0]).name() == typeid(*reel[2]).name()))
        {
            similar2Shapes = true;
        }
    }

    // checks if LR shapes are similar
    bool similarLRShapes = false;
    if (typeid(*reel[0]).name() == typeid(*reel[2]).name()) {
        similarLRShapes = true;
    }

    // returns int value to multiply bet, depending on similar shapes & shape sizes
    if (similar2Shapes && screenAreaMatch) {
        return 3;
    }
    else if (similar3Shapes)
    {
        return 2;
    }
    else if (greaterScreenMid) {
        return 1;
    }
    else if (similarLRShapes) {
        return 0;
    }
    else {
        return -1;
    }
}

// displays message explaining outcome of the bet
void SlotMachine::winMessage() {
    if (betMultiplier == 3) {
        cout << "Jackpot! 2 Similar Shapes AND 2 Equal Screen Areas" << "Congratulations! you win 2 times your bet: "
             << bet << "\nYou now have " << tokens << " tokens" << endl;

    }
    else if (betMultiplier == 2)
    {
        cout << "Three similar shapes\n" << "Congratulations! you win 2 times your bet: "
             << bet << "\nYou now have " << tokens << " tokens" << endl;

    }
    else if (betMultiplier == 1) {
        cout << "Middle > Left + Right, in Screen Areas\n" << "Congratulations! you win your bet: "
             << bet << "\nYou now have " << tokens << " tokens" << endl;

    }
    else if (betMultiplier == 0) {

        cout << "Lucky this time!\n" << "You don't win, you don't lose, you are safe!"
             << "\nYou now have " << tokens << " tokens" << endl;
    }
    else {
        cout << "Oh no!\n" << "You lose your bet"
             << "\nYou now have " << tokens << " tokens" << endl;
    }
}





