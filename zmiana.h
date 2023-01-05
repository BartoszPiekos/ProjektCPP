class Zmiana{
    private:
int inHour,inMin;
int outHour,outMin;
int hours;

public:
    Zmiana(int=100,int=100,int=100,int=100,int=0);
void read();
void write();
int getInHour() const;
int getInMin() const;
int getOutHour() const;
int getOutMin() const;
void setInHour(int inH);
void setInMin(int inM);
void setOutHour(int outH);
void setOutMin(int outM);
int hoursCounter();
int minsCounter();
};
