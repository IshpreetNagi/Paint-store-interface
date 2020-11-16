//Date: Sept. 28, 2020
//Name: Ishpreet Nagi

#include <iostream> //adding all my libraries
#include <bits/stdc++.h>
using namespace std;

double addprice, HST; //declaring my global variables

void welcome() //creating the function that welcomes the user to the shop
{
    time_t currentTime = time(0); //this code will read and collect the time and date from the computer on which it is being run
    char * dateTime = ctime(&currentTime);

    cout << "\t\t\t\t\t\t\tWelcome" << endl; //messages for the user
    cout << "\t\t\t\t\t\t\t  to" << endl;

    cout << "\t\t\t\t______       _             ______     _       _  " << endl; //art for the user
    cout << "\t\t\t\t|  _  \\     | |            | ___ \\   (_)     | | " << endl;
    cout << "\t\t\t\t| | | |_   _| |_   ___  __ | |_/ /_ _ _ _ __ | |_ ___ " << endl;
    cout << "\t\t\t\t| | | | | | | | | | \\ \\/ / |  __/ _` | | '_ \\| __/ __| " << endl;
    cout << "\t\t\t\t| |/ /| |_| | | |_| |>  <  | | | (_| | | | | | |_\\__ \\ " << endl;
    cout << "\t\t\t\t|___/  \\__,_|_|\\__,_/_/\\_\\ \\_|  \\__,_|_|_| |_|\\__|___/\n" << endl;

    cout << "\t\t\t\t\t       " << dateTime << endl; //displays the time and date which had been collected before
}

double LB(double a) //double function to find the total price the paint will cost according to the amount of gallons being bought, it gets the gallons being cost and returns the cost
{
    double total; //creating a variable to store the total cost

    total = a*20.90; //multiples the gallons by the price of one gallon that paint color and stores it in the variable

    return(total); //returns the variable that holds the cost of that man gallons of paint
}

double GRAY(double b) //double function to find the total price the paint will cost according to the amount of gallons being bought, it gets the gallons being cost and returns the cost
{
    double total2; //creating a variable to store the total cost

    total2 = b*22.50; //multiples the gallons by the price of one gallon that paint color and stores it in the variable

    return(total2); //returns the variable that holds the cost of that man gallons of paint
}

double WH(double c) //double function to find the total price the paint will cost according to the amount of gallons being bought, it gets the gallons being cost and returns the cost
{
    double total3; //creating a variable to store the total cost

    total3 = c*23.25; //multiples the gallons by the price of one gallon that paint color and stores it in the variable

    return(total3);
}

double R(double d) //double function to find the total price the paint will cost according to the amount of gallons being bought, it gets the gallons being cost and returns the cost
{
    double total4; //creating a variable to store the total cost

    total4 = d*21.95; //multiples the gallons by the price of one gallon that paint color and stores it in the variable

    return(total4); //returns the variable that holds the cost of that man gallons of paint
}

double G(double e) //double function to find the total price the paint will cost according to the amount of gallons being bought, it gets the gallons being cost and returns the cost
{
    double total5; //creating a variable to store the total cost

    total5 = e*19.95; //multiples the gallons by the price of one gallon that paint color and stores it in the variable

    return(total5);
}

double W(double f) //double function to find the total price the paint will cost according to the amount of gallons being bought, it gets the gallons being cost and returns the cost
{
    double total6; //creating a variable to store the total cost

    total6 = f*18.45; //multiples the gallons by the price of one gallon that paint color and stores it in the variable

    return(total6); //returns the variable that holds the cost of that man gallons of paint
}

double billing(double lightblue, double gray, double wheat, double red, double green, double white) //gets the total cost of each paint being bought, stores into the variable and the function gets their total cost
{
    addprice = lightblue + gray + wheat + red + green + white; //adds the cost of all the paints to get the total cost of them without tax

    HST = addprice*0.13; //multiplies the price by the tax percentage to get total cost of the tax

    double f = addprice + HST; //creates a variable where the tax cost and the paints cost are added to get the final total cost of the paints and stores the number in the variable

    return(f); //returns the variable that holds the final total cost back to the main
}

void payment(double totalprice) //gets the total final cost of the paint with the tax and everything to allow the payment method to start
{
    string method; //creates variables
    double amount;

    cout << "\nWill you be paying with CASH or CREDIT: "; //tells the user what they need to enter

    do{ //begins the do-while loop that would allow for the user to enter the option again if they enter an illegal input
        cin >> method; //gets the input from the user and stores it into the variable
        transform(method.begin(), method.end(), method.begin(), ::tolower); //transforms whatever string value the user enters all into lowercase letters to make it easier for the code to read and so it makes the possible entries from the user be smaller and the code could easily adapt to each one
        if(method != "cash" && method != "credit") //the if statement that if met displays a kind of error message for the user
        {
            cout << "\nPlease choose one the given payment methods: "; //error message
        }
    } while(method != "cash" && method != "credit"); //the requirements that once met, will cause the do-while loop to repeat, thus not letting them exit the loop until they have entered the correct input


    if(method == "cash")
    {
        totalprice = floorf(totalprice * 100) / 100; //rounds whatever the total price value is to two decimal places to make it easier for the program to pay for it
        pay: //the destination of the goto statement so that the code could restart when called to

        cout << "\nEnter amount: $"; //message for the user

        do{ //begins the do-while loop that would allow for the user to enter the option again if they enter an illegal input
            cin >> amount; //stores the input from the user in the variable
            if(amount <= 0)
            {
                cout << "\nPlease enter an amount higher than zero: $"; //error message
            }
        } while(amount <= 0); //the requirements that once met, will cause the do-while loop to repeat, thus not letting them exit the loop until they have entered the correct input

        totalprice = totalprice - amount; //subtracts the amount the user is paying in cash from the total price of the paint

        if(totalprice > 0)
        {
            cout << "\nYou still owe a total of $" << totalprice << endl; //tells the user how much they still owe
            goto pay; //tells the code where it now needs to go so that the user gets the option to pay again
        }
        else if(totalprice == 0)
        {
            cout << "\nPAYMENT COMPLETE!" << endl; //message for the user
        }
        else
        {
            cout << "\nPAYMENT COMPLETE!\n" << endl; //message for the user
            cout << "Your change today is $" << (totalprice*-1) << endl; //tells the user how much their change is and multiples whatever the total final price if by -1 to make it positive
        }

    }
    else
    {
        cout << "\nProcessing request...\n" << endl; //messages for the user
        cout << "REQUEST ACCEPTED" << endl;
        cout << "PAYMENT COMPLETE" << endl;
    }

    cout << "\n\t\t\t\t   Thank you for shopping at DULUX PAINTS" << endl; //messages for the user
    cout << "\t\t\t\t\t  Hope to see you very soon!" << endl;
    cout << "\t\t\t\t\t      Have fun painting!" << endl;
    system("pause"); //pauses the screen so the user gets a chance to properly look at everything before they can press a button to keep moving
}

int main()
{
    system("color F1"); //changes the color of the background and text

    restartall: //the destination of the goto statement so that the code could start from when called to

    welcome(); //calls the welcome function
    system("pause"); //pauses the screen so the user gets a chance to properly look at everything before they can press a button to keep moving
    system("CLS"); //clears the screen and allows for the new content to be displayed cleanly

    double glb, gg, gw, gr, ggreen, gwhite; //creates variables
    double lightblue, gray, wheat, red, green, white;
    char answerq;
    string resetans;
    cout << fixed << setprecision(2); //makes it so all double variables only display numbers up to two decimal places
    lightblue = 0; //sets all these variables equal to zero
    gray = 0;
    wheat = 0;
    red = 0;
    green = 0;
    white = 0;
    glb = 0;
    gg = 0;
    gr = 0;
    gw = 0;
    ggreen = 0;
    gwhite = 0;
    ggreen = 0;
    gwhite = 0;

    cout << "\t\t\t\t    ***Latest Shipment of Paint has not arrived yet***" << endl; //messages for the user
    cout << "\t\t\t\t***Paint listed below is all that is in stock currently***" << endl;
    cout << "\t\t\t\t ***We apologize for any inconvenience this may cause***\n" << endl;

    reset: //the destination of the goto statement so that the code could start from when called to


    cout << "Available Paint Options:\n" << endl; //messages for the user
    cout << "LIGHTBLUE: $20.90/Gallon" << endl;
    cout << "GRAY: $22.50/Gallon" << endl;
    cout << "WHEAT: $23.25/Gallon" << endl;
    cout << "RED: $21.95/Gallon" << endl;
    cout << "GREEN: $19.95/Gallon" << endl;
    cout << "WHITE: $18.45/Gallon\n" << endl;

    while(true) //starts the while true loop that will keep repeating as long as the user wants to buy paint
    {
        string color; //creates these variables
        char ans;
        double gallons;

        cout << "Enter the paint color you would like: "; //tells the user what they need to enter

        do{ //begins the do-while loop that would allow for the user to enter the option again if they enter an illegal input
            cin >> color; //stores the input in the variable
            transform(color.begin(), color.end(), color.begin(), ::tolower); //transforms whatever string value the user enters all into lowercase letters to make it easier for the code to read and so it makes the possible entries from the user be smaller and the code could easily adapt to each one
            if (color != "lightblue" && color != "gray" && color != "wheat" && color != "red" && color != "green" && color != "white") //the if statement that if met displays a kind of error message for the user
            {
                cout << "\nSorry but that paint is not in stock currently, please choose a color which is available: "; //error message
            }
        }while(color != "lightblue" && color != "gray" && color != "wheat" && color != "red" && color != "green" && color != "white"); //the requirements that once met, will cause the do-while loop to repeat, thus not letting them exit the loop until they have entered the correct input


        cout << "Number of gallons you require: "; cin >> gallons; //tells the user what they need to enter and stores the input in the variable

        if(color == "lightblue")
        {
            glb += gallons; //adds the gallons entered by the user into the color specific gallon variable and makes the variable equal the sum
            lightblue = LB(glb); //sends the number of color specific gallons variable to the functions and then stores the return variable in the variable

            if(lightblue < 0) //checks to see if the number that was returned from the function is negative
            {
                lightblue = 0; //if it is negative, makes the cost of the paint and the the gallons of that color being bought equal zero the prevent a negative number being printed on the receipt or being used in the calculations
                glb = 0;
            }
        }
        else if(color == "gray")
        {
            gg += gallons; //adds the gallons entered by the user into the color specific gallon variable and makes the variable equal the sum
            gray = GRAY(gg); //sends the number of color specific gallons variable to the functions and then stores the return variable in the variable

            if(gray < 0) //checks to see if the number that was returned from the function is negative
            {
                gray = 0; //if it is negative, makes the cost of the paint and the the gallons of that color being bought equal zero the prevent a negative number being printed on the receipt or being used in the calculations
                gg = 0;
            }
        }
        else if(color == "wheat")
        {
            gw += gallons; //adds the gallons entered by the user into the color specific gallon variable and makes the variable equal the sum
            wheat = WH(gw); //sends the number of color specific gallons variable to the functions and then stores the return variable in the variable

            if(wheat < 0) //checks to see if the number that was returned from the function is negative
            {
                wheat = 0; //if it is negative, makes the cost of the paint and the the gallons of that color being bought equal zero the prevent a negative number being printed on the receipt or being used in the calculations
                gw = 0;
            }
        }
        else if(color == "red")
        {
            gr += gallons; //adds the gallons entered by the user into the color specific gallon variable and makes the variable equal the sum
            red = R(gr); //sends the number of color specific gallons variable to the functions and then stores the return variable in the variable

            if(red < 0) //checks to see if the number that was returned from the function is negative
            {
                red = 0; //if it is negative, makes the cost of the paint and the the gallons of that color being bought equal zero the prevent a negative number being printed on the receipt or being used in the calculations
                gr = 0;
            }
        }
        else if(color == "green")
        {
            ggreen += gallons; //adds the gallons entered by the user into the color specific gallon variable and makes the variable equal the sum
            green = G(ggreen); //sends the number of color specific gallons variable to the functions and then stores the return variable in the variable

            if(green < 0) //checks to see if the number that was returned from the function is negative
            {
                green = 0; //if it is negative, makes the cost of the paint and the the gallons of that color being bought equal zero the prevent a negative number being printed on the receipt or being used in the calculations
                ggreen = 0;
            }
        }
        else
        {
            gwhite += gallons; //adds the gallons entered by the user into the color specific gallon variable and makes the variable equal the sum
            white = W(gwhite); //sends the number of color specific gallons variable to the functions and then stores the return variable in the variable

            if(white < 0) //checks to see if the number that was returned from the function is negative
            {
                white = 0; //if it is negative, makes the cost of the paint and the the gallons of that color being bought equal zero the prevent a negative number being printed on the receipt or being used in the calculations
                gwhite = 0;
            }
        }

        cout << "Would you like to continue shopping(Y/N): "; //tells the user what they need to enter

        do{ //begins the do-while loop that would allow for the user to enter the option again if they enter an illegal input
            cin >> ans; //stores the input in the variable
            ans = tolower(ans); //converts the char character into lowercase no matter what
            if(ans != 'y' && ans != 'n') //the if statement that if met displays a kind of error message for the user
            {
                cout << "\nPlease choose between Y or N: "; //error message
            }
        } while(ans != 'y'&& ans != 'n'); //the requirements that once met, will cause the do-while loop to repeat, thus not letting them exit the loop until they have entered the correct input

        if(ans == 'y')
        {
            cout << endl; //creates a space
            continue; //restarts the entire while true loop
        }
        else
        {
            break; //breaks out of the loop
        }
    }

    if(glb == 0 && gg == 0 && gw == 0 && gr == 0 && ggreen == 0 && gwhite == 0) //checks to see if all the paint gallons being bought are equal to zero, meaning that the user is not buying anything, this prevents the user from entering the receipt and payment phase
    {
        cout << "\n\t\t\t\t\tWe see you are not buying anything!" << endl; //message for the user
        cout << "\t\t  Please start again and buy something or I will have to ask you to leave the store.\n" << endl; //messages for the user

        cout << "Please enter 'EXIT' to leave the store, 'RESTART' to enter again!" << endl; //tells the user what they need to enter

        do{ //begins the do-while loop that would allow for the user to enter the option again if they enter an illegal input
            cout << "\nYour decision: "; cin >> resetans; //gets the input from the user and stores in the variable
            transform(resetans.begin(), resetans.end(), resetans.begin(), ::tolower); //transforms whatever string value the user enters all into lowercase letters to make it easier for the code to read and so it makes the possible entries from the user be smaller and the code could easily adapt to each one
            if (resetans != "restart" && resetans != "exit") //the if statement that if met displays a kind of error message for the user
            {
                cout << "\nPlease choose between 'RESTART' or 'EXIT'!" << endl; //error message
            }
        }while(resetans != "restart" && resetans != "exit"); //the requirements that once met, will cause the do-while loop to repeat, thus not letting them exit the loop until they have entered the correct input

        if(resetans == "restart")
        {
            system("CLS"); //clears the screen and allows for the new content to be displayed cleanly
            goto reset; //tells the code where it now needs to go
        }
        else
        {
            cout << "Thank you for at least stopping by!" << endl; //message for the user
            system("pause"); //pauses the screen so the user gets a chance to properly look at everything before they can press a button to keep moving
            system("CLS"); //clears the screen and allows for the new content to be displayed cleanly
            goto restartall; //tells the code where it now needs to go
        }
    }

    cout << "\nProceeding to checkout...\n" << endl; //message for the user
    system("pause"); //pauses the screen so the user gets a chance to properly look at everything before they can press a button to keep moving
    system("CLS"); //clears the screen and allows for the new content to be displayed cleanly
    double totalprice = billing(lightblue, gray, wheat, red, green, white); //sends the total costs of each paint to the billing function and then stores the value that is returned in the variable

    cout.width(40); //helps to center the message below on the screen
    cout << "***********************************" << endl; //message for the user
    cout.width(27); //helps to center the message below on the screen
    cout << "Final Bill" << endl; //message for the user
    cout.width(28); //helps to center the message below on the screen
    cout << "DULUX PAINTS" << endl; //message for the user
    cout.width(41); //helps to center the message below on the screen
    cout << "***********************************\n" << endl; //message for the user

    cout << "Items List:" << endl; //message for the user
    if(glb > 0) //these are the if statements that see if there is even a value for the specific paint color and only display the ones the user is buying on the screen
    {
        cout << glb << " Gallons of LIGHTBLUE Paint: $" << lightblue << endl; //displays the amount of gallons of paint being bought along with how much it will cost
    }
    if(gg > 0)
    {
        cout << gg << " Gallons of GRAY Paint: $" << gray << endl; //displays the amount of gallons of paint being bought along with how much it will cost
    }
    if(gw > 0)
    {
        cout << gw << " Gallons of WHEAT colored Paint: $" << wheat << endl; //displays the amount of gallons of paint being bought along with how much it will cost
    }
    if(gr > 0)
    {
        cout << gr << " Gallons of RED Paint: $" << red << endl; //displays the amount of gallons of paint being bought along with how much it will cost
    }
    if(ggreen > 0)
    {
        cout << ggreen << " Gallons of GREEN Paint: $" << green << endl; //displays the amount of gallons of paint being bought along with how much it will cost
    }
    if(gwhite > 0)
    {
        cout << gwhite << " Gallons of WHITE Paint: $" << white << endl; //displays the amount of gallons of paint being bought along with how much it will cost
    }

    cout << endl; //creates a empty space in between texts

    cout.width(18); //helps to create a gap between the left edge of the screen and the text
    cout << "Subtotal: $" << addprice << endl; //displays the total cost of the paint before tax
    cout << endl; //creates a empty space in between texts
    cout.width(16); //helps to create a gap between the left edge of the screen and the text
    cout << "HST%: 13%" << endl; //message for the user
    cout << endl; //creates a empty space in between texts
    cout.width(20); //helps to create a gap between the left edge of the screen and the text
    cout << "HST Amount: $" << HST << endl; //displays the exact cost of the tax
    cout << endl; //creates a empty space in between texts
    cout.width(21); //helps to create a gap between the left edge of the screen and the text
    cout << "Final Total: $" << totalprice << endl; //the final total cost of the paint

    cout << "\nWould you like to add or remove an item from your order(Y/N): "; //gives the user one last chance to do change their purchase

    while(true) //starts the while true loop that would allow for the user to enter the option again if they enter an illegal input
    {
        cin >> answerq; //stores the input into the variable

        answerq = tolower(answerq); //converts the char character into lowercase no matter what

        if (answerq == 'y')
        {
            cout << endl; //creates a space between the texts
            goto reset; //tells the code where it now needs to go
        }
        else if(answerq == 'n')
        {
            break; //breaks out of the loop
        }
        else
        {
            cout << "Please enter either Y or N: "; //error message
        }
    }
    payment(totalprice); //sends the total final cost of the the pain plus tax to the payment function
    system("CLS"); //clears the screen and allows for the new content to be displayed cleanly
    goto restartall; //tells the code where it now needs to go
}
