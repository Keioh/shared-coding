#include "header\object.h"


//初期化処理(xの初期位置,yの初期位置,画像への相対パス,αブレンドの速さ,円の場合は半径を入力)
void Object::setup(float pos_x, float pos_y, char* path, float alpha_speed, float radius)
{
	graphics.load(path);//画像読み込み

	position_x = graphics_position_x = pos_x;
	position_y = graphics_position_y = pos_y;
	if (alpha_speed >= 255)//alpha_speedが255以上ならalphaに255を代入
	{ 
		alpha = 255;
	}
	else
	{
		alpha = 0;
	}
	a_speed = alpha_speed;//α値を加算させる量をa_speedに代入

	Impact::setup(position_x, position_y, graphics.getWidth(), graphics.getHeight(), radius);//当たり判定
}

//アニメーション処理。
void Object::update(float moved_x, float moved_y, float rate)
{
	alpha += a_speed;
	if (alpha >= 255)alpha = 255;
	if (alpha <= 0)alpha = 0;

	position_x = (moved_x * rate) + graphics_position_x;//画像をx方向に移動させる。
	position_y = (moved_y * rate) + graphics_position_y;//画像をy方向に移動させる。

	Impact::update(position_x, position_y);//ヒットボックスを移動させる。
}

//描写
void Object::draw(bool wire)
{
	//ofEnableBlendMode(OF_BLENDMODE_ALPHA);

	if (Impact::hit == true)//ヒットしてたら画像を少し明るく表示する
	{
		if (Impact::click == true) //ヒットかつクリックしていたらさらに明るく表示する。
		{ 
			ofSetColor(255, 255, 255, alpha); 
		}
		else
		{
			ofSetColor(235, 235, 235, alpha);
		}
	}
	else
	{
		ofSetColor(200, 200, 200, alpha);//ヒットしていなかったら暗く表示する。
	}

	graphics.draw(position_x,position_y);//画像の表示
	if (wire == true)Impact::draw();//当たり判定のワイヤーを表示
}

//ofApp::mouseMoved(int x,int y)の中に記述する。マウスを動かしたときにヒット判定をさせる処理
void Object::mouseMovedUpdate(int x, int y)
{
	Impact::mouseMovedUpdate(x, y);//当たり判定
}

//ofApp::mousePressedUpdate(int x, int y, int button)の中に記述する。マウスがヒットしているときにボタンを押したときの処理。
void Object::mousePressedUpdate(int x, int y, int button, int kind_button)
{
	Impact::mousePressedUpdate(x, y, button, kind_button);//当たり判定
}

//ofApp::mouseReleasedUpdate(int x, int y, int button)の中に記述する。マウスがヒットしているときにボタンを離したときの処理。
void Object::mouseReleasedUpdate(int x, int y, int button, int kind_button)
{
	Impact::mouseReleasedUpdate(x, y, button, kind_button);//当たり判定
}