#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/

int main()
{
    int first=1;

    // game loop
    while (1) {
        int x;
        int y;
        int nextCheckpointX; // x position of the next check point
        int nextCheckpointY; // y position of the next check point
        int nextCheckpointDist; // distance to the next checkpoint
        int nextCheckpointAngle; // angle between your pod orientation and the direction of the next checkpoint
        cin >> x >> y >> nextCheckpointX >> nextCheckpointY >> nextCheckpointDist >> nextCheckpointAngle; cin.ignore();
        int opponentX;
        int opponentY;
        cin >> opponentX >> opponentY; cin.ignore();

        // Write an action using cout. DON'T FORGET THE "<< endl"
        // To debug: cerr << "Debug messages..." << endl;
        int obx=opponentX, oby = opponentY,cx=nextCheckpointX,cy=nextCheckpointY;
        string thrust_str="";
        cerr <<"Debug message"<<endl;
        int thrust=100;
        int angle=abs(nextCheckpointAngle);
        if(y<cy && x<cx)
        {
            if(nextCheckpointAngle<0)
            {
                nextCheckpointY -=600;
            }
            else
            {
                nextCheckpointY +=600;
            }
        }
        else if(y<cy && x>cx)
        {
            if(nextCheckpointAngle<0)
            {
                nextCheckpointY +=600;
            }
            else
            {
                nextCheckpointY -=600;
            }
            
        }
        else if(y>cy && x<cx)
        {
            if(nextCheckpointAngle<0)
            {
                nextCheckpointY +=600;
            }
            else
            {
                nextCheckpointY -=600;
            }
        }
        else
        {
            if(nextCheckpointAngle<0)
            {
                nextCheckpointY -=600;
            }
            else
            {
                nextCheckpointY +=600;
            }
        }
        if(nextCheckpointAngle>70 || nextCheckpointAngle<-70)
        {
            thrust=0;
            thrust_str = to_string(thrust);
            // if(y<nextCheckpointY)
            // {
            //     nextCheckpointY -= 500;
            // }
            // else
            //     nextCheckpointY += 500;
        }
        else if(nextCheckpointAngle>30 || nextCheckpointAngle<-30)
        {
            thrust=60 + (70-angle);
            thrust_str = to_string(thrust);
            
        }
        else{
            if(nextCheckpointDist>3000)
            {
                   thrust_str ="100";
                   if(first==1 && nextCheckpointAngle<40 && nextCheckpointAngle>-40){
                    thrust_str = "BOOST";
                    first=0;
                   }
            }
            else if(nextCheckpointDist>1000)
            {
                thrust=100;
                thrust_str ="100";
            }
            else{
                thrust = 20 + nextCheckpointDist/20;
                thrust_str = to_string(thrust);
            }
        }
    
        if(first==1 && nextCheckpointAngle<40 && nextCheckpointAngle>-40){
            thrust_str = "BOOST";
            first=0;
        }
        cerr<<" angle "<<nextCheckpointAngle<<" dist "<<nextCheckpointDist<<endl;
        cerr<<" thrust "<<thrust<<endl;
        cerr<<" thrust string "<<thrust_str;
        
        cout << nextCheckpointX << " " << nextCheckpointY << " "<<thrust_str << endl;
    }
}