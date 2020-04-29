#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#define pi 3.141592
using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/
class pod
{
    public:
    int x,y;
    //pod_slope is in rad +ve for above x axis and - for below x axis
    int thrust;
    float pod_slope;
    int opx,opy;
    int checkx,checky,check_angle;
    int boostUsed=0;
    
    void set_param(int a,int b, int tx, int ty, int ta){
        x = a;
        y = b;

        //set next target(checkpoint) and use angle to get angle of ship
        checkx = tx;
        checky = ty;
        check_angle = ta;

        //calculating the angle of pod
        
        //need to check targetx != x else n/0 error
        double pt_slope= atan(-1*double((checky-y)*1.0)/double(checkx-x));
        if( checkx-x > 0)
        {
            pod_slope = check_angle*pi/180 + pt_slope;
            if(pod_slope>pi)
            {
                pod_slope = pod_slope - 2*pi;
            }
            else if(pod_slope< -pi)
            {
                pod_slope = pod_slope + 2*pi;
            }
        }
        else
        {
            pod_slope = check_angle*pi/180 + pt_slope;
            pod_slope = pod_slope+pi;
            if(pod_slope>pi)
                pod_slope = pod_slope - 2*pi;
            else if(pod_slope< -pi)
                pod_slope = pod_slope + 2*pi;
            // if(pod_slope<0)
            //     pod_slope = pi + pod_slope;
            // else
            //     pod_slope = pod_slope- pi;
        }
        // cerr<<" pod slope = "<<pod_slope*180/pi<<endl;
        
    }
    void set_op(int a, int b){
        opx = a;
        opy = b;
    }
    int dist_from_pod(int a, int b)
    {
        float dist_ab = (x-a)*(x-a) + (y-b)*(y-b);
        dist_ab = sqrt(dist_ab);
        return dist_ab;
    }
    int angle_from_pod(int a, int b)
    {
        float slope_ab=0;
        if(a==x)
            slope_ab = -1.0*(b-y)/0.00001;
        else slope_ab = -1.0*(b-y)/(a-x);

        slope_ab = atan(slope_ab);
        if(a-x <0)
        {
            slope_ab = pi + slope_ab;
            if(slope_ab>pi)
                slope_ab = slope_ab- 2*pi;
        }
        slope_ab = pod_slope - slope_ab;

        //adjusting the sign for clockwise(+ve) and anticlockwise(-ve)
        if(slope_ab>pi)
            slope_ab = slope_ab - pi -pi;
        else if(slope_ab < -pi)
            slope_ab = slope_ab +pi +pi;

        slope_ab = slope_ab*180/pi;
        return slope_ab;
    }
};
class checkpt
{
    public:
    int xckpt,yckpt,distckpt;
};
class calc_thrust : public pod
{
    public:
    int thrust_com(int dist)
    {
        // check_angle = deg;
        float rad = check_angle*1.0*pi/180;
        //scalling distance
        // dist = dist/25;
        dist = dist/20;
        float thru;
        // thru = dist*cos(abs(rad));
        cerr<<"checkpt angle = "<<check_angle<<" dist = "<<dist<<endl;
        thru = dist*1.0*(70-abs(check_angle))/100;
        // thru = 30 + 6*thru/10;
        if(thru<0)
            thru=0;
        cerr<<" thrust cos = "<<thru<<endl;
        return thru;
    }
    int thrust_linear(int dest)
    {
        int k = 2000;
        float thru = 20 + 80*dest/k;
        return thru;
    }
};
class maps : public pod, public checkpt
{
    public:
    int checkdist;
    int laps=1;
    int max_dist=0;
    vector<pair<pair<int,int>,int>> checkpoints;
    bool all_checkpoints_found=0;

    //to insert checkpoints
    void insertCheckpoints(int xcor,int ycor, int dest)
    {
        if(checkpoints.size()==0)
        {
            max_dist=dest;
            checkpoints.push_back(make_pair(make_pair(xcor,ycor),dest));
            return ;
        }
        else if((*checkpoints.end())!= make_pair(make_pair(xcor,ycor),dest))
        {
            if(max_dist<dest)
                max_dist = dest;
            checkpoints.push_back(make_pair(make_pair(xcor,ycor),dest));
        }
        else{
            all_checkpoints_found=1;
            laps++;
        }
    }
    //check if all checkpoints are found or not

    bool checkpoints_found()
    {
        return all_checkpoints_found;
    }
    int dist_of_points(int a,int b,int x, int y)
    {
        int tem = (a-x)*(a-x) + (b-y)*(b-y);
        tem = sqrt(tem);
        return tem;
    }
};

int main()
{
    int first=1;
    
    pod my_pod;
    maps my_map;
    calc_thrust ct;
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
        int opx=opponentX, opy = opponentY,cx=nextCheckpointX,cy=nextCheckpointY,ca=nextCheckpointAngle;
        int cd = nextCheckpointDist;
        string thrust_str="100";
        
        //setting the parameters
        pair<pair<int,int>,int> nextcheckpt=make_pair(make_pair(cx,cy),cd);
        my_pod.set_param(x,y,cx,cy,ca);
        my_map.insertCheckpoints(cx,cy,cd);
        int opponentAngle =my_pod.angle_from_pod(opx,opy);
        int opponentDistance= my_pod.dist_from_pod(opx,opy);
        int thrust=100;
        int angle=abs(ca);
        cerr <<"Debug message"<<endl;
        cerr<<"opponent angle = "<<opponentAngle<<endl;
        
        if(ca>90 || ca<-90)
        {
            thrust=0;
            thrust_str = to_string(thrust);
        }
        else if(ca>65 || ca<-65)
        {
            thrust = 20 + (90-abs(ca))*2;
            thrust_str = to_string(thrust);
        }
        else if(ca>40 || ca<-40)
        {
            if(cd>5000)
            {
                thrust=100;
                thrust_str ="100";   
            }
            else if(cd>2000)
            {
                thrust=90;
                thrust_str ="90";
            }
            else{
                cerr<<"above 40 and thrust_com\n";
                // calc_thrust ct;
                thrust = ct.thrust_com(cd);
                thrust_str = to_string(thrust);
            }
        }
        else if( ca>30 || ca<-30){
            if(cd>2000)
            {
                thrust=100;
                thrust_str ="100";
            }
            else{
                cerr<<"above 30 and thrust_com\n";
                // calc_thrust ct;
                thrust = ct.thrust_com(cd);
                thrust_str = to_string(thrust);
            }
        }
        else if(ca>15 || ca< -15)
        {
            cerr<<" less than 30 \n";
            if(my_pod.boostUsed==0 && cd>=4000){
                thrust_str = "BOOST";
                thrust=100;
                my_pod.boostUsed=1;
                cerr<<"boosting..";
                
            }
            else if(cd>2000)
            {
                thrust=100;
                thrust_str = to_string(thrust);
            }
            else{
                cerr<<" less than 30 and thrust_con \n";
                // calc_thrust ct;
                thrust = ct.thrust_com(cd);
                thrust_str = to_string(thrust);
            }
            
        }
        else{
            if(my_pod.boostUsed==0 && cd>=4000){
                thrust_str = "BOOST";
                thrust=100;
                my_pod.boostUsed=1;
                cerr<<"boosting..";
            }
            else if(cd>2000)
            {
                thrust=100;
                thrust_str = to_string(thrust);
            }
            else{
                cerr<<" less than 30 and thrust_con \n";
                // calc_thrust ct;
                thrust = ct.thrust_linear(cd);
                // thrust=80;
                // if(cd<800)
                //     thrust = 30;
                thrust_str = to_string(thrust);
            }

        }

        if(abs((cx+x)/2 -x) > 600 && abs((cy+y)/2-y) >600){
            cx = (cx+x)/2;
            cy = (cy+y)/2;
        }
        //aggerssive behaviour
        if(abs(opponentAngle)<15 && abs(ca)<15 && opponentDistance<1000)
        {
            cerr<<"aggressive 100\n";
            thrust=100;
            thrust_str = to_string(thrust);
            cx = (cx+opx)/2;
            cy = (cy+opy)/2;
        }
        //boost
        if(my_map.laps ==3 && nextcheckpt==my_map.checkpoints.back() && my_map.boostUsed==0)
        {
            if(ca<15 && ca>-15)
            {
                thrust=100;
                thrust_str = "BOOST";
                my_map.boostUsed=1;
            }
        }
        



        
            
        cerr<<" angle "<<nextCheckpointAngle<<" dist "<<nextCheckpointDist<<endl;
        cerr<<" thrust "<<thrust<<endl;
        cerr<<" thrust string "<<thrust_str;
        
        cout << cx << " " << cy << " "<<thrust_str << endl;
    }
}