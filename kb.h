#ifndef KB_H
#define KB_H

char * readStr(){
    int i = 0;
    char * buff = (char *) 0xb9200;
    bool read = true;

    while(read){
        if(inportb(0x64) & 0x1){
            switch(inportb(0x60)){
//                case 1:
//                    print("got it ");
//                    print((char*)(inportb(0x60)));
//                    print("\n");
//                    buff[i] = '1';
//                    break;
                case 2:
                    print("1");
                    buff[i] = '1';
                    i++;
                    break;
                case 3:
                    print("2");
                    buff[i] = '2';
                    i++;
                    break;
                case 4:
                    print("3");
                    buff[i] = '3';
                    i++;
                    break;
                case 5:
                    print("4");
                    buff[i] = '4';
                    i++;
                    break;
                case 6:
                    print("5");
                    buff[i] = '5';
                    i++;
                    break;
                case 7:
                    print("6");
                    buff[i] = '6';
                    i++;
                    break;
                case 8:
                    print("7");
                    buff[i] = '7';
                    i++;
                    break;
                case 9:
                    print("8");
                    buff[i] = '8';
                    i++;
                    break;
                case 10:
                    print("9");
                    buff[i] = '9';
                    i++;
                    i++;
                    break;
                case 11:
                    print("0");
                    buff[i] = '0';
                    i++;
                    break;
                case 12:
                    print("-");
                    buff[i] = '-';
                    i++;
                    break;
                case 13:
                    print("=");
                    buff[i] = '=';
                    i++;
                    break;

                case 14:                //Backspace
                    if(i>0){
                        buff[i] = 8;
                        buff[i+1] = 0;
                        print(&buff[i]);
                        i--;
                    }
                    break;

                case 16:
                    print("q");
                    buff[i] = 'q';
                    i++;
                    break;
                case 17:
                    print("w");
                    buff[i] = 'w';
                    i++;
                    break;
                case 18:
                    print("e");
                    buff[i] = 'e';
                    i++;
                    break;
                case 19:
                    print("r");
                    buff[i] = 'r';
                    i++;
                    break;
                case 20:
                    print("t");
                    buff[i] = 't';
                    i++;
                    break;
                case 21:
                    print("y");
                    buff[i] = 'y';
                    i++;
                    break;
                case 22:
                    print("u");
                    buff[i] = 'u';
                    i++;
                    break;
                case 23:
                    print("i");
                    buff[i] = 'i';
                    i++;
                    break;
                case 24:
                    print("o");
                    buff[i] = 'o';
                    i++;
                    break;
                case 25:
                    print("p");
                    buff[i] = 'p';
                    i++;
                    break;
                case 26:
                    print("[");
                    buff[i] = '[';
                    i++;
                    break;
                case 27:
                    print("]");
                    buff[i] = ']';
                    i++;
                    break;

                case 28:                //Enter
                    print("\n");
                    read = false;
                    break;

                case 30:
                    print("a");
                    buff[i] = 'a';
                    i++;
                    break;
                case 31:
                    print("s");
                    buff[i] = 's';
                    i++;
                    break;
                case 32:
                    print("d");
                    buff[i] = 'd';
                    i++;
                    break;
                case 33:
                    print("f");
                    buff[i] = 'f';
                    i++;
                    break;
                case 34:
                    print("g");
                    buff[i] = 'g';
                    i++;
                    break;
                case 35:
                    print("h");
                    buff[i] = 'h';
                    i++;
                    break;
                case 36:
                    print("j");
                    buff[i] = 'j';
                    i++;
                    break;
                case 37:
                    print("k");
                    buff[i] = 'k';
                    i++;
                    break;
                case 38:
                    print("l");
                    buff[i] = 'l';
                    i++;
                    break;
                case 39:
                    print(";");
                    buff[i] = ';';
                    i++;
                    break;
                case 40:
                    print("\"");
                    buff[i] = '"';
                    i++;
                    break;
                case 43:
                    print("\\");
                    buff[i] = '\\';
                    i++;
                    break;
                case 44:
                    print("z");
                    buff[i] = 'z';
                    i++;
                    break;
                case 45:
                    print("x");
                    buff[i] = 'x';
                    i++;
                    break;
                case 46:
                    print("c");
                    buff[i] = 'c';
                    i++;
                    break;
                case 47:
                    print("v");
                    buff[i] = 'v';
                    i++;
                    break;
                case 48:
                    print("b");
                    buff[i] = 'b';
                    i++;
                    break;
                case 49:
                    print("n");
                    buff[i] = 'n';
                    i++;
                    break;
                case 50:
                    print("m");
                    buff[i] = 'm';
                    i++;
                    break;
                case 51:
                    print(",");
                    buff[i] = ',';
                    i++;
                    break;
                case 52:
                    print(".");
                    buff[i] = '.';
                    i++;
                    break;
                case 53:
                    print("/");
                    buff[i] = '/';
                    i++;
                    break;
                case 57:
                    print(" ");
                    buff[i] = ' ';
                    i++;
                    break;

                case 58:        //caps lock
                    break;

                case 72:        //Up
                    break;
                case 75:        //LEFT
                    break;
                case 77:        //Right
                    break;
                case 80:        //Down
                    break;

            }        
        }
    }

    buff[i] = 0;
    return buff;
}


#endif
