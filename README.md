# ASCII Art Gallery
 
## Background
To test out an Arduino micro SD card module, I wrote some simple programs that would open the SD card and print the contents into the serial monitor. Since the micro SD card was loaded with text files that formed ASCII art once zoomed out far enough, the program became an art gallery of sorts.

## Hardware Requirements and Wiring
- Arduino UNO
- Micro SD card module
- Micro SD card
- Jumper wires

| Arduino Pin | Micro SD Card Module |
|-|-|
| GND | GND |
| 5V | VCC |
| D12 | MISO |
| D11 | MOSI |
| D13 | SCK |
| D4 | CS |

## Generating ASCII Art

The micro SD card needs to be loaded with text files (.txt) that contain ASCII art. An easy way to do this is to visit https://www.text-image.com/convert/ascii.html and convert your images to ASCII form. Select "Extra contrast" for a cleaner result. ASCII images look better when zoomed out, but the Arduino serial monitor has a limit to how much you can zoom out, so I suggest making the image width equal to 350 characters.

Your text files need to be saved with file names following the format of `number.txt` (e.g. `1.txt`). 

## Running the program

Once you have your micro SD card loaded with your ASCII art of choice, plug it into the micro SD card module and run one of the following programs on your Arduino UNO. Regardless of which program you run, change the variable `numPictures` to match the number of text files you have saved on your micro SD card.
- `ASCII_Art_Gallery_Sequential.ino` displays all of your images in sequential order
- `ASCII_Art_Gallery_Randomized.ino` displays the images in a randomized* order

Once the program is running, open the serial monitor, set the baudrate to 115200, and zoom out to see your beautiful ASCII art pieces being displayed.

*It's not really random. Rather, a random image will be displayed so long as it wasn't the last or second-last image to be displayed. This was done to add a bit of variance to the art gallery.
