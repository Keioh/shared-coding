//�����蔻��̊�{�N���X

#pragma once
#include <math.h>
#include "header\define.h"
#include "ofMain.h"


class Impact : public ofBaseApp
{

public:
	bool hit, click;//�q�b�g�m�F�ϐ��ƁA�N���b�N�m�F�ϐ�
	float position_x, position_y;//�|�W�V����
	float width, height;//�傫��
	float radius_buffer;//���a

	void setup(float pos_x, float pos_y, float size_x = 0, float size_y = 0, float radius = -1);//�����蔻��̏�����(pos_x,posy�͔���J�n�ʒu�Asize_x,size_y�͔���̑傫��,radius��-1�̎��͔����BOX��0�ȏ�̎���CIRCLE����ɂȂ�܂��B
	void update(float moved_x, float moved_y);//Impact�������Ƃ��̏���
	void draw(int thick = 2);//���肳���͈͂����C���[�ŕ`�ʂ��܂��B�q�b�g������ԁA�q�b�g�Ȃ��ŐB(���̑����͏�����2)

	void mouseMovedUpdate(int x, int y);//ofApp::mouseMoved(int x,int y)�̒��ɋL�q����B�}�E�X�𓮂������Ƃ��Ƀq�b�g����������鏈���B
	void mousePressedUpdate(int x, int y, int button, int kind_button);//ofApp::mousePressedUpdate(int x, int y, int button)�̒��ɋL�q����B�}�E�X���q�b�g���Ă���Ƃ��Ƀ{�^�����������Ƃ��̏����B
	void mouseReleasedUpdate(int x, int y, int button, int kind_button);//ofApp::mouseReleasedUpdate(int x, int y, int button)�̒��ɋL�q����B�}�E�X���q�b�g���Ă���Ƃ��Ƀ{�^���𗣂����Ƃ��̏����B

};