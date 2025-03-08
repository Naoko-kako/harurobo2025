/*
RRST 春ロボ2025
カメラからsubscribeする
*/
#include <rclcpp/rclcpp.hpp>
#include <std_msgs/msg/int32_multi_array.hpp>

class ScoreManager : public rclcpp::Node(const std_msgs::Int32MultiArray& msg)
{   
    public:
      ScoreManager()
      :Node("score_manager"), count_(0)
      {
        Subscription_= this->create_subscription<std_msgs::msg::Int32MultiArray>(
            "topic",10,std::bind(&ScoreManager::ScoreCallback, this,std::placeholders::_1);

        Publisher_ = this->create_publisher<std_msgs::msg::Int32>("topic",10);
        )
      } 

      private:
       rclcpp::Subscription<std_msgs::msg::Int32MultiArray>::SharedPtr getscore_sub;
       rclcpp::Publisher<std_msgs::msg::Int32>::Sharedptr getscore_pub
       //0-5が赤、6-11が青
       

       void countCallback(
        const std_msgs::msg::Int32MultiArray::SharedPtr gatscore_msg) {


          int score[12] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
          
          for(int i = 0,i < 12, i++){
            if(get_score->data[i]==1){
              score[i]++;
            }
                
          }


          int red_a = score[0]; //竜宮エリアに進入＋１０
          int red_b = score[1]; //玉が宝箱に入っている＋２０
          int red_c = score[2]; //珊瑚が宝箱に入っている　+２５
          int red_d = score[3];
          int red_e = score[4];
          int red_f = score[5];
          int blue_a = score[6]; 
          int blue_b = score[7];
          int blue_c = score[8];
          int blue_d = score[9];
          int blue_e = score[10];
          int blue_f = score[11];

          int point = 0;

          //コーン(珊瑚)を回収する
          
          class state1{
                point = 25*2 + 20*2;
                red_c = 25*2;
                red_e = 20*2;
          }
          

          //竜宮エリアに進入
          class state2{
                point += 10;
                int state2;
                red_a = 10;
          }

          //ボール(玉)の回収
          class state3{
                point += 20*4 + 15*4;
                //宝箱達成
                point += 100;  
                int state3;   
                printf("RYUGU!");
                red_b = 20*4;
                red_f = 15*4;
                red_d = 100;
          }
         
        }
    
}


int main(int argc, char **argv) {
    auto node = std::make_shared<Subscriber>();
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}