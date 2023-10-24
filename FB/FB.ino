#include <SoftwareSerial.h>
#include <AFMotor.h>

AF_DCMotor motor_L(1);  // 왼쪽 바퀴 1번
AF_DCMotor motor_R(4);  // 오른쪽 바퀴 4번

// 초음파센서 출력핀(trig) & 입력핀(echo)
int TrigPin = A0;
int EchoPin = A1;
long duration, distance;    // 기간, 거리

// 초음파 센서 함수
void Obstacle_Check();
void Distance_Measurement();
void Forward();
void Backward();
void Right();
void Left();
void Stop();

void setup() {
  // put your setup code here, to run once:
  motor_L.setSpeed(175);    // 왼쪽 바퀴 속도
  motor_L.run(RELEASE);     // 왼쪽 바퀴 대기 상태
  motor_R.setSpeed(200);    // 오른쪽 바퀴 속도
  motor_R.run(RELEASE);     // 오른쪽 바퀴 대기 상태
}

void loop() {
  // put your main code here, to run repeatedly:

// 전진
  motor_L.run(FORWARD);     
  motor_R.run(BACKWARD);     
  delay(2000);              

// 멈춤
  motor_L.run(RELEASE);     
  motor_R.run(RELEASE);     
  delay(1000);              

// 후진
  motor_L.run(BACKWARD);
  motor_R.run(FORWARD);
  delay(2000);

// 멈춤
  motor_L.run(RELEASE);
  motor_R.run(RELEASE);
  delay(1000);
}
