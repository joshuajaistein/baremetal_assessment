#include <stdio.h>

// here we define the structure with the required members
struct quaternion {
    float real;
    float i;    
    float j;    
    float k;    
};

// here we use a struct func to bring the q() format and avoid individual inputs
struct quaternion q(float real, float i, float j, float k) {
    struct quaternion q_instance;
    q_instance.real = real;
    q_instance.i = i;
    q_instance.j = j;
    q_instance.k = k;
    return q_instance;
}

// struct func to multiply two quaternions
struct quaternion mul(struct quaternion q1, struct quaternion q2) {
    struct quaternion result;

    /* Quaternion multiplication formula implementation ...
    */
    result.real = q1.real * q2.real - q1.i * q2.i - q1.j * q2.j - q1.k * q2.k;
    result.i = q1.real * q2.i + q1.i * q2.real + q1.j * q2.k - q1.k * q2.j;
    result.j = q1.real * q2.j - q1.i * q2.k + q1.j * q2.real + q1.k * q2.i;
    result.k = q1.real * q2.k + q1.i * q2.j - q1.j * q2.i + q1.k * q2.real;

    return result;
}

// struct func to calculate the q1_bar and q2_bar
struct quaternion q_bar(struct quaternion q) {
    /* q_bar implementation */

    struct quaternion result;
    result.real = q.real;
    result.i = -q.i;  
    result.j = -q.j; 
    result.k = -q.k; 
    return result;
}

// float func to calculate the dot product of two quaternions
float q_dot(struct quaternion q1, struct quaternion q2) {
    return (q1.real * q2.real) + (q1.i * q2.i) + (q1.j * q2.j) + (q1.k * q2.k);
}

// print func to print a quaternion in the form "a + bi + cj + dk"
void printQuaternion(struct quaternion q) {
    printf("%.2f + %.2fi + %.2fj + %.2fk\n", q.real, q.i, q.j, q.k);
}

int main() {
    // Create quaternions using the 'q' function directly without individual user input
    struct quaternion q1 = q(1, 2, 3, 4);
    struct quaternion q2 = q(5, 6, 7, 8);

    printf("Quaternion q1: ");
    printQuaternion(q1);
    printf("Quaternion q2: ");
    printQuaternion(q2);

    // we now ask user to give a input ...

    int user_input ;

    printf("Quaternion operations ...\n");
    printf("1. Multiply two quaternions q1 and q2n...\n");
    printf("2. q_bar of a quaternion q ...\n");
    printf("3. dot product of quaternion q1 and q2 ... \n");
    scanf("%d" , &user_input) ;

    switch(user_input)
    {
        case 1 : 
            {
                 // Multiply two quaternions
                 struct quaternion result = mul(q1, q2);
                 printf("\nThe product of q1 and q2 is: \n");
                 printQuaternion(result);
                 break;
            }
        case 2 :
            {
                 // Calculate q1_bar and q2_bar
                 struct quaternion q_conjugate = q_bar(q1);
                 printf("\nThe conjugate of q1 is: \n");
                 printQuaternion(q_conjugate);

                 struct quaternion q_conjugate_2 = q_bar(q2);
                 printf("\nThe conjugate of q2 is: \n");
                 printQuaternion(q_conjugate_2);

                 break ;
            }

        case 3 :
            {
                 // Calculate the dot product of q1 and q2
                 float dot_product = q_dot(q1, q2);
                 printf("\nThe dot product of q1 and q2 is: %.2f\n", dot_product);
                 break ;
            }

        default :

                 printf("enter valid option !\n");
                 break ;
    }

    return 0;
}

