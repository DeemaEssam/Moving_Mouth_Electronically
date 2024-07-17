// Define pins for rows and columns
#define ROW1 13
#define ROW2 12
#define ROW3 11
#define ROW4 10
#define ROW5 9
#define ROW6 8
#define ROW7 7
#define ROW8 6

#define COL1 5
#define COL2 4
#define COL3 3
#define COL4 2
#define COL5 A4
#define COL6 A3
#define COL7 A2
#define COL8 A1

// Create arrays for row and column pins
const int row[] = {ROW1, ROW2, ROW3, ROW4, ROW5, ROW6, ROW7, ROW8};
const int col[] = {COL1, COL2, COL3, COL4, COL5, COL6, COL7, COL8};

// Define patterns to display on the LED matrix
int A[8][8] = {  
  {0, 0, 0, 0, 0, 0, 0, 0},
  {0, 1, 0, 0, 0, 0, 1, 0},
  {1, 0, 1, 0, 0, 1, 0, 1},
  {0, 1, 0, 0, 0, 0, 1, 0},
  {0, 0, 0, 0, 0, 0, 0, 0},
  {0, 1, 0, 0, 0, 0, 1, 0},
  {0, 0, 1, 1, 1, 1, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0}
};

int R[8][8] = {  
  {0, 0, 0, 0, 0, 0, 0, 0},
  {0, 1, 0, 0, 0, 0, 1, 0},
  {1, 0, 1, 0, 0, 1, 0, 1},
  {0, 1, 0, 0, 0, 0, 1, 0},
  {0, 0, 0, 0, 0, 0, 0, 0},
  {0, 1, 1, 1, 1, 1, 1, 0},
  {0, 0, 1, 1, 1, 1, 0, 0},
  {0, 0, 0, 1, 1, 0, 0, 0}
};

int Y[8][8] = {  
  {0, 0, 0, 0, 0, 0, 0, 0},
  {0, 1, 0, 0, 0, 0, 1, 0},
  {1, 0, 1, 0, 0, 1, 0, 1},
  {0, 1, 0, 0, 0, 0, 1, 0},
  {0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 1, 1, 1, 1, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0}
};

void setup() {
  Serial.begin(9600);  // Initialize serial communication
  pinMode(A0, INPUT_PULLUP);  // Set A0 as input with internal pull-up resist
  
  // Set all row pins as outputs and initialize them to LOW
  for (int i = 2; i <= 13; i++) {
    pinMode(i, OUTPUT);
    digitalWrite(i, LOW);
  }

  // Set all column pins as outputs and initialize them to LOW
  pinMode(A4, OUTPUT);
  digitalWrite(A4, LOW);
  pinMode(A3, OUTPUT);
  digitalWrite(A3, LOW);
  pinMode(A2, OUTPUT);
  digitalWrite(A2, LOW);
  pinMode(A1, OUTPUT);
  digitalWrite(A1, LOW);
}

void loop() {
  if (digitalRead(A0) == LOW) {
    led(A);  // Display pattern A
  } else if (digitalRead(A0) == HIGH) {
    led(R);  // Display pattern R
    led(Y);  // Display pattern Y
  }
}

void led(int matrix[8][8]) {
  for (int i = 0; i < 10; i++) {  // Reduce the number of repetitions for faster transitions
    for (int c = 0; c < 8; c++) {  // Loop through each column
      digitalWrite(col[c], HIGH);  // Activate the current column
      for (int r = 0; r < 8; r++) {  // Loop through each row in the current column
        digitalWrite(row[r], matrix[r][c] == 1 ? LOW : HIGH);  // Set the row based on the matrix value
      }
      delay(1);  // Short delay for LED visibility
      for (int r = 0; r < 8; r++) {  // Turn off all rows after displaying
        digitalWrite(row[r], HIGH);
      }
      digitalWrite(col[c], LOW);  // Deactivate the current column
    }
    if (digitalRead(A0) == LOW) {
      break;  // Exit the loop if the button is pressed
    }
  }
}
