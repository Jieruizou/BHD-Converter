#define Z 20
//方形按钮
struct SquareButton {
	int x, y;   //(x,y)坐标
	int width, height;  //大小
};

//从记录返回按钮
SquareButton Return = {
	340, 20,
	100, 45,
};

//确定执行按钮
SquareButton button = {
	30, 400,
	100, 45,
};

//清空按钮
SquareButton button1{
	175, 400,
	100, 45,
};

//跳到记录按钮
SquareButton button2 = {
	320, 400,
	100, 45,
};

//前2进制按钮
SquareButton button3 = {//按钮间+100,字间+25
	32, 134,
	15, 15,
};

//前8进制按钮
SquareButton button4 = {
	132, 134,
	15, 15,
};

//前10进制按钮
SquareButton button5 = {
	232, 134,
	15, 15,
};

//前16进制按钮
SquareButton button6 = {
	332, 134,
	15, 15,
};

//后2进制按钮
SquareButton button7 = {
	32, 220,
	15, 15,
};


//后8进制按钮
SquareButton button8 = {
	132, 220,
	15, 15,
};

//后10进制按钮
SquareButton button9 = {
	232, 220,
	15, 15,
};

//后16进制按钮
SquareButton button10 = {
	332, 220,
	15, 15,
};
