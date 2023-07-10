#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <SDL.h>
#include "SDL_ttf.h"
#include <windows.h>
#include <random>
#include <chrono>
 
#define WHITE	stv::rgb(255,255,255)
#define RED		stv::rgb(255,0,0)
#define BLUE	stv::rgb(0,0,255)
#define GREEN	stv::rgb(0,255,0)
#define YELLOW  stv::rgb(255,255,0)
#define PURPLE  stv::rgb(255,0,255)

#define UC (unsigned char)
#define INT (int)
#define FLOAT (float)
#define DOUBLE (double)
#define BOOL (bool)
#define CHAR (char)
#define CCP const char*
#define VINT std::vector<int>

#define NOW std::chrono::system_clock::now()
#define time std::chrono::system_clock::time_point
#define RAD / 57.2957795
#define second * 1000
#define default_texture SDL_Texture* texture = IMG_LoadTexture(ren, "FILE");
#define Arial "C:\\Users\\User\\source\\repos\\Platformer\\Platformer\\fonts\\arial.ttf"

#define SDL_INCLUDE_VULKAN

static const int screen_width = 1920;
static const int screen_height = 1010;
static SDL_Window* win = SDL_CreateWindow("Platformer", 0, 30, screen_width, screen_height, SDL_WINDOW_VULKAN);
static SDL_Renderer* ren = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED);

namespace stv {

	struct Vector3 {
		double x = 0;
		double y = 0;
		double z = 0;

		void operator += (float n) { x += n; y += n; z += n; }
		void operator += (Vector3 n) { x += n.x; y += n.y; z += n.z; }

		void operator -= (float n) { x -= n; y -= n; z -= n; }
		void operator -= (Vector3 n) { x -= n.x; y -= n.y; z -= n.z; }

		void operator *= (unsigned n) { x *= n; y *= n; z *= n; }
		void operator *= (Vector3 n) { x *= n.x; y *= n.y; z *= n.z; }

		void operator /= (float n) { x /= n; y /= n; z /= n; }
		void operator /= (Vector3 n) { x /= n.x; y /= n.y; z /= n.z; }

		void operator = (std::vector<int> vector3) { x = vector3[0]; y = vector3[1]; z = vector3[2]; }
		void operator = (std::vector<float> vector3) { x = vector3[0]; y = vector3[1]; z = vector3[2]; }
		void operator = (std::vector<double> vector3) { x = vector3[0]; y = vector3[1]; z = vector3[2]; }

		bool operator == (Vector3 var) { return (var.x == x and var.y == y and var.z == z); }

		bool operator != (Vector3 var) { return !(var.x == x and var.y == y and var.z == z); }

		Vector3 operator + (float n) { return Vector3(x + n, y + n, z + n); }
		Vector3 operator + (Vector3 n) { return Vector3(x + n.y, y + n.y, z + n.z); }
		Vector3 operator - (float n) { return Vector3(x - n, y - n, z - n); }
		Vector3 operator - (Vector3 n) { return Vector3(x - n.y, y - n.y, z - n.z); }
		Vector3 operator * (float n) { return Vector3(x * n, y * n, z * n); }
		Vector3 operator * (Vector3 n) { return Vector3(x * n.y, y * n.y, z * n.z); }
		Vector3 operator / (float n) { return Vector3(x / n, y / n, z / n); }
		Vector3 operator / (Vector3 n) { return Vector3(x / n.y, y / n.y, z / n.z); }

		friend std::ostream& operator << (std::ostream& os, const Vector3 vector3)
		{
			os << "(" << vector3.x << ", " << vector3.y << "," << vector3.z << ")";
			return os;
		};

		Vector3() { x = 0; y = 0; z = 0; }

		Vector3(double p_x, double p_y, double p_z) { x = p_x; y = p_y; z = p_z; }

		Vector3(std::vector<int> vector3) { x = vector3[0]; y = vector3[1]; z = vector3[2]; }
		Vector3(std::vector<float> vector3) { x = vector3[0]; y = vector3[1]; z = vector3[2]; }
		Vector3(std::vector<double> vector3) { x = vector3[0]; y = vector3[1]; z = vector3[2]; }

		SDL_FPoint SDLvector() {
			return SDL_FPoint{ (float)x,(float)y };
		}

	};

	struct Vector2 {
		double x = 0;
		double y = 0;

		void operator += (float n) { x += n; y += n; }
		void operator += (Vector2 n) { x += n.x; y += n.y; }

		void operator -= (float n) { x -= n; y -= n; }
		void operator -= (Vector2 n) { x -= n.x; y -= n.y; }

		void operator *= (unsigned n) { x *= n; y *= n; }
		void operator *= (Vector2 n) { x *= n.x; y *= n.y; }

		void operator /= (float n) { x /= n; y /= n; }
		void operator /= (Vector2 n) { x /= n.x; y /= n.y; }

		void operator = (std::vector<int> vector2) { x = vector2[0]; y = vector2[1]; }
		void operator = (std::vector<float> vector2) { x = vector2[0]; y = vector2[1]; }
		void operator = (std::vector<double> vector2) { x = vector2[0]; y = vector2[1]; }

		bool operator == (Vector2 var) { return (var.x == x and var.y == y); }

		bool operator != (Vector2 var) { return !(var.x == x and var.y == y); }

		bool operator >= (Vector2 var) { return (sqrt(pow(var.x, 2) + pow(var.y, 2)) <= sqrt(pow(x, 2) + pow(y, 2))); }

		bool operator <= (Vector2 var) { return (sqrt(pow(var.x, 2) + pow(var.y, 2)) >= sqrt(pow(x, 2) + pow(y, 2))); }

		bool operator < (Vector2 var) { return (sqrt(pow(var.x, 2) + pow(var.y, 2)) > sqrt(pow(x, 2) + pow(y, 2))); }

		bool operator > (Vector2 var) { return (sqrt(pow(var.x, 2) + pow(var.y, 2)) < sqrt(pow(x, 2) + pow(y, 2))); }

		Vector2 operator + (float n) { return Vector2(x + n, y + n); }
		Vector2 operator + (Vector2 n) { return Vector2(x + n.y, y + n.y); }
		Vector2 operator - (float n) { return Vector2(x - n, y - n); }
		Vector2 operator - (Vector2 n) { return Vector2(x - n.y, y - n.y); }
		Vector2 operator * (float n) { return Vector2(x * n, y * n); }
		Vector2 operator * (Vector2 n) { return Vector2(x * n.y, y * n.y); }
		Vector2 operator / (float n) { return Vector2(x / n, y / n); }
		Vector2 operator / (Vector2 n) { return Vector2(x / n.y, y / n.y); }

		std::string operator ! () {
			return std::to_string((int)x) + ";" + std::to_string((int)y);
		}

		friend std::ostream& operator << (std::ostream& os, const Vector2 vector2)
		{
			os << "(" << vector2.x << ", " << vector2.y << ")";
			return os;
		};

		Vector2() { x = 0; y = 0; }

		Vector2(double p_x, double p_y) { x = p_x; y = p_y; }

		Vector2(std::vector<int> vector2) { x = vector2[0]; y = vector2[1]; }
		Vector2(std::vector<float> vector2) { x = vector2[0]; y = vector2[1]; }
		Vector2(std::vector<double> vector2) { x = vector2[0]; y = vector2[1]; }

		SDL_FPoint SDLvector() {
			return SDL_FPoint{ (float)x,(float)y };
		}

	};

	template <class _Ty, class _Alloc = std::allocator<_Ty>>
	struct Vector {
		std::vector<_Ty> data;

		Vector() {}

		Vector(std::vector<_Ty> vec) {
			data = vec;
		}

		Vector2 vector2(int i = 0) {
			i *= 2;
			if (data.size() < 2 + i) { return Vector2(0,0); }
			return Vector2(data[0 + i], data[1 + i]);
		}

		Vector3 vector3(int i = 0) {
			i *= 3;
			if (data.size() < 3+i) { return Vector3(data[0 + i], data[1 + i], 0); }
			return Vector3(data[0 + i], data[1 + i], data[2 + i]);
		}

		SDL_Rect SDL_rect(int i = 0) {
			i *= 4;
			if (data.size() < 4 + i) { return SDL_Rect(data[0 + i], data[1 + i], 0, 0); }
			return SDL_Rect(data[0 + i], data[1 + i], data[2 + i], data[3 + i]);
		}

		std::vector<_Ty> vector() {
			return data;
		}

		std::vector<_Ty> subVector(int start, int length) {
			auto vecstart = data.begin() + start;
			auto vecend = data.begin() + start + length;
			return std::vector<_Ty>(vecstart, vecend);
		}

		void append(_Ty n) {
			data.push_back(n);
		}
		void append(Vector n) {
			data.insert(data.end(), n.data.begin(), n.data.end());
		}
		void append(std::vector<_Ty> n) {
			data.insert(data.end(), n.begin(), n.end());
		}

		Vector<_Ty> operator + (_Ty n) {
			std::vector<_Ty> vec = data;
			vec.push_back(n);
			return vec;
		}
		std::vector<_Ty> operator + (std::vector<_Ty> n) {
			std::vector<_Ty> vec = data;
			vec.insert(vec.end(), n.begin(), n.end());
			return vec;
		}
		Vector operator + (Vector n) {
			Vector vec;
			vec.data = data;
			vec.data.insert(vec.data.end(), n.data.begin(), n.data.end());
			return vec;
		}

		_Ty operator [] (int i) { return data[i]; }

		friend std::ostream& operator << (std::ostream& os, const Vector vec)
		{
			if (!vec.data.size()) return os;
			os << "(";
			for (int i = 0; i < vec.data.size() - 1; i++) {
				os << vec.data[i] << ", ";
			}
			os << vec.data[vec.data.size() - 1] << ")";
			return os;
		};

		void operator += (_Ty n) {
			data.push_back(n);
		}
		void operator += (Vector n) {
			data.insert(data.end(), n.data.begin(), n.data.end());
		}
		void operator += (std::vector<_Ty> n) {
			data.insert(data.end(), n.begin(), n.end());
		}
	};

	struct rgb {
		int blue;
		int red;
		int green;
		int alpha;

		rgb(int r, int g, int b, int a = 255) {
			blue = b;
			red = r;
			green = g;
			alpha = a;
		}

		SDL_Color SDLcolor() {
			return SDL_Color{ UC red, UC green, UC blue, UC alpha };
		}

	};

	struct Text {

		SDL_Surface* surface;
		SDL_Texture* texture;
		SDL_Rect Message_rect;

		Text(CCP text, CCP path, int size, rgb color, Vector2 position, Vector2 frame_size) {

			surface = TTF_RenderText_Solid(TTF_OpenFont(path, 1000), text, color.SDLcolor());
			texture = SDL_CreateTextureFromSurface(ren, surface);

			Message_rect = SDL_Rect(VINT{INT position.x, INT position.y, INT frame_size.x, INT frame_size.y});
			SDL_FreeSurface(surface);

		}

		Text() {}
	};

	struct object {
		Vector2 position = Vector2(0, 0);
		Vector2 size = Vector2(0, 0);
		rgb color = rgb(255, 255, 255, 255);

		object() {
			position = Vector2(0, 0);
			size = Vector2(0, 0);
			color = rgb(255, 255, 255, 255);
		}

		object(Vector2 pos, Vector2 p_size, rgb p_color = rgb(255, 255, 255, 255)) {
			position = pos;
			size = p_size;
			color = p_color;
		}

		void draw(bool fill = true) {

		}

	};

	class matrix3d {
	private:
		std::vector<std::vector<std::vector<int>>> data;

	public:
		matrix3d(int p_x = 1, int p_y = 1, int p_z = 1, int def = 0) {

			for (int k = 0; k < p_x; k++) {
				data.push_back(std::vector<std::vector<int>>{});
				for (int j = 0; j < p_y; j++) {
					data[k].push_back(std::vector<int> {});
					for (int i = 0; i < p_z; i++) {
						data[k][j].push_back(def);
					}
				}
			}
		}

		std::vector<std::vector<int>> operator [] (int n) {
			if (n <= data.size()) return data[n];
		}

		friend std::ostream& operator << (std::ostream& os, const matrix3d matrix) {
			for (const std::vector<std::vector<int>>& element1 : matrix.data) { for (const std::vector<int>& element2 : element1) { for (const int& element3 : element2) { os << element3 << " "; } os << std::endl; } os << std::endl; }
			return os;
		}
	};


	void Write(Text text) {
		text.Message_rect.x = text.Message_rect.x + screen_width / 2 - text.Message_rect.w / 2;
		text.Message_rect.y = screen_height / 2 - text.Message_rect.y - text.Message_rect.h / 2;

		SDL_RenderCopy(ren, text.texture, 0, &text.Message_rect);
	}

	void Write(CCP text, CCP path, int size, rgb color, Vector2 position, Vector2 frame_size) {
		position.x = position.x + screen_width / 2 - frame_size.x / 2;
		position.y = screen_height / 2 - position.y - frame_size.y / 2;

		SDL_Surface* surface = TTF_RenderText_Solid(TTF_OpenFont(path, 1000), text, color.SDLcolor());
		SDL_Texture* texture = SDL_CreateTextureFromSurface(ren, surface);

		SDL_Rect Message_rect = SDL_Rect(VINT{INT position.x, INT position.y, INT frame_size.x, INT frame_size.y});
		SDL_FreeSurface(surface);

		SDL_RenderCopy(ren, texture, 0, &Message_rect);
	}

	void Write(CCP text, CCP path, int size, rgb color, VINT rect) {
		rect[0] = rect[0] + screen_width / 2 - rect[2] / 2;
		rect[1] = screen_height / 2 - rect[1] - rect[3] / 2;

		SDL_Surface* surface = TTF_RenderText_Solid(TTF_OpenFont(path, 1000), text, color.SDLcolor());
		SDL_Texture* texture = SDL_CreateTextureFromSurface(ren, surface);

		SDL_Rect Message_rect = SDL_Rect(rect);
		SDL_FreeSurface(surface);

		SDL_RenderCopy(ren, texture, 0, &Message_rect);
	}

	std::vector<object*> objects;
	std::vector<Text*> texts;
}

namespace geo {

	void hline(Sint16 x1, Sint16 x2, Sint16 y) { SDL_RenderDrawLine(ren, x1, y, x2, y); }

	void circle(stv::Vector2 pos, int rad, stv::rgb color) {
		pos.x = pos.x + screen_width / 2;
		pos.y = screen_height / 2 - pos.y;

		Sint16 cx = 0;
		Sint16 ocx = (Sint16)0xffff;
		Sint16 ocy = (Sint16)0xffff;
		Sint16 df = 1 - rad;
		Sint16 d_e = 3;
		Sint16 d_se = -2 * rad + 5;
		Sint16 xpcx, xmcx, xpcy, xmcy;
		Sint16 ypcy, ymcy, ypcx, ymcx;

		SDL_SetRenderDrawColor(ren, color.red, color.green, color.blue, color.alpha);

		if (rad == 0) {
			SDL_RenderDrawPoint(ren, pos.x, pos.y);
			return;
		}

		while (cx <= rad) {
			xpcx = pos.x + cx;
			xmcx = pos.x - cx;
			xpcy = pos.x + rad;
			xmcy = pos.x - rad;
			if (ocy != rad) {
				if (rad > 0) {
					ypcy = pos.y + rad;
					ymcy = pos.y - rad;
					hline(xmcx, xpcx, ypcy);
					hline(xmcx, xpcx, ymcy);
				}
				else {
					hline(xmcx, xpcx, pos.y);
				}
			}
			if (cx != rad) {
				if (cx > 0) {
					ypcx = pos.y + cx;
					ymcx = pos.y - cx;
					hline(xmcy, xpcy, ymcx);
					hline(xmcy, xpcy, ypcx);
				}
				else {
					hline(xmcy, xpcy, pos.y);
				}
			}
			if (df < 0) {
				df += d_e;
				d_e += 2;
				d_se += 2;
			}
			else {
				df += d_se;
				d_e += 2;
				d_se += 4;
				rad--;
			}
			cx++;
		}
	}

	void triangle(std::vector<stv::Vector2> points, stv::rgb color) {

		std::vector<SDL_Vertex> verts;

		for (auto& point : points) {
			point.x = point.x + screen_width / 2;
			point.y = screen_height / 2 - point.y;
			verts.push_back({ point.SDLvector(), color.SDLcolor(), SDL_FPoint{ 0 } });
		}
		SDL_RenderGeometry(ren, nullptr, verts.data(), verts.size(), nullptr, 0);
	}

	void triangle(std::vector<stv::Vector3> points, stv::rgb color) {
		
		std::vector<SDL_Vertex> verts;

		for (auto& point : points) {
			point.x = point.x + screen_width / 2;
			point.y = screen_height / 2 - point.y;
			verts.push_back({ point.SDLvector(), color.SDLcolor(), SDL_FPoint{ 0 } });
		}
		SDL_RenderGeometry(ren, nullptr, verts.data(), verts.size(), nullptr, 0);
	}

	void triangle2(stv::Vector2 pos, stv::Vector2 A, stv::Vector2 B, stv::Vector2 C, stv::rgb color, int rotation = 90) {

		A -= B / 2;

		stv::Vector2 c1(A.x * cos(rotation RAD) - A.y * sin(rotation RAD), A.x * sin(rotation RAD) + A.y * cos(rotation RAD));
		stv::Vector2 c2((A.x + B.x) * cos(rotation RAD) - A.y * sin(rotation RAD), (A.x + B.x) * sin(rotation RAD) + A.y * cos(rotation RAD));
		stv::Vector2 c3(A.x * cos(rotation RAD) - (A.y + C.y) * sin(rotation RAD), A.x * sin(rotation RAD) + (A.y + C.y) * cos(rotation RAD));

		c1 += pos;
		c2 += pos;
		c3 += pos;

		triangle(std::vector<stv::Vector2>{c1, c2, c3}, color);
	}

	void rectangle(stv::Vector2 position, stv::Vector2 size, stv::rgb color, double rotation = 90, stv::Vector2 pos = stv::Vector2(0, 0)) {

		pos -= size / 2;

		stv::Vector2 c1(pos.x * cos(rotation RAD) - pos.y * sin(rotation RAD), pos.x * sin(rotation RAD) + pos.y * cos(rotation RAD));
		stv::Vector2 c2((pos.x + size.x) * cos(rotation RAD) - pos.y * sin(rotation RAD), (pos.x + size.x) * sin(rotation RAD) + pos.y * cos(rotation RAD));
		stv::Vector2 c3(pos.x * cos(rotation RAD) - (pos.y + size.y) * sin(rotation RAD), pos.x * sin(rotation RAD) + (pos.y + size.y) * cos(rotation RAD));
		stv::Vector2 c4((pos.x + size.x) * cos(rotation RAD) - (pos.y + size.y) * sin(rotation RAD), (pos.x + size.x) * sin(rotation RAD) + (pos.y + size.y) * cos(rotation RAD));

		c1 += position; c2 += position; c3 += position; c4 += position;

		triangle(std::vector<stv::Vector2>{c1, c2, c3}, color);
		triangle(std::vector<stv::Vector2>{c4, c2, c3}, color);
	}

	stv::Vector3 rotate3D(stv::Vector3 position, stv::Vector3 rotation, float p = 0) {

		rotation = rotation RAD;

		float a = rotation.x;
		float b = rotation.y;
		float c = rotation.z;

		float xx = cos(c) * cos(a) - sin(c) * sin(a) * sin(b);
		float xy = cos(c) * sin(a) * sin(b) + sin(c) * cos(a);
		float yx = -cos(c) * sin(a) - sin(c) * cos(a) * sin(b);
		float yy = cos(c) * cos(a) * sin(b) - sin(c) * sin(a);
		float zx = -sin(c) * cos(b);
		float zy = cos(c) * pow(cos(b), 2);

		float x2 = position.x * (1 - position.x * p);
		float y2 = position.y * (1 - position.y * p);
		float z2 = position.z * (1 - position.z * p);

		position.x = x2 * xx + y2 * yx + z2 * zx;
		position.y = x2 * xy + y2 * yy + z2 * zy;
		position.z = z2;

		return position;
	}

	void cube(stv::Vector3 position, stv::Vector3 size, stv::rgb color, stv::Vector3 rotation = stv::Vector3(90, 90, 90), stv::Vector3 pos = stv::Vector3(0, 0, 0)) {

		position -= size / 2;

		std::vector<stv::Vector3> points;

		points.push_back(rotate3D(position, rotation));																		// 0
		points.push_back(rotate3D(stv::Vector3(position.x + size.x, position.y, position.z), rotation));					// 1
		points.push_back(rotate3D(stv::Vector3(position.x, position.y + size.y, position.z), rotation));					// 2
		points.push_back(rotate3D(stv::Vector3(position.x, position.y, position.z + size.z), rotation));					// 3
		points.push_back(rotate3D(stv::Vector3(position.x + size.x, position.y + size.x, position.z), rotation));			// 4
		points.push_back(rotate3D(stv::Vector3(position.x + size.x, position.y, position.z + size.z), rotation));			// 5
		points.push_back(rotate3D(stv::Vector3(position.x, position.y + size.y, position.z + size.z), rotation));			// 6
		points.push_back(rotate3D(stv::Vector3(position.x + size.x, position.y + size.y, position.z + size.z), rotation));	// 7

		if (cos(rotation.x RAD) > 0) {
			triangle(std::vector<stv::Vector3>{points[2], points[6], points[4]}, YELLOW);
			triangle(std::vector<stv::Vector3>{points[7], points[6], points[4]}, YELLOW);
		}
		else {
			triangle(std::vector<stv::Vector3>{points[0], points[1], points[3]}, PURPLE);
			triangle(std::vector<stv::Vector3>{points[5], points[1], points[3]}, PURPLE);
		}

		if (sin(rotation.x RAD) > 0) {
			triangle(std::vector<stv::Vector3>{points[1], points[4], points[5]}, WHITE);
			triangle(std::vector<stv::Vector3>{points[7], points[4], points[5]}, WHITE);
		}
		else {
			triangle(std::vector<stv::Vector3>{points[0], points[2], points[3]}, GREEN);
			triangle(std::vector<stv::Vector3>{points[6], points[2], points[3]}, GREEN);
		}

		if (sin(rotation.y RAD) < 0) {
			triangle(std::vector<stv::Vector3>{points[3], points[5], points[6]}, BLUE);
			triangle(std::vector<stv::Vector3>{points[7], points[5], points[6]}, BLUE);
		}
		else {
			triangle(std::vector<stv::Vector3>{points[0], points[1], points[2]}, RED);
			triangle(std::vector<stv::Vector3>{points[4], points[1], points[2]}, RED);
		}

	}

}

namespace gme {

	class Player {
	public:
		SDL_Texture* texture = NULL;

		stv::Vector2 position = stv::Vector2(0, 0);
		stv::Vector2 size = stv::Vector2(0, 0);

		float health = 100;
		float speed = 10;
		float mass = 10;
		stv::Vector2 velocity;
		float jump = 10;

		Player(SDL_Texture* p_texture, stv::Vector2 p_position, stv::Vector2 p_size, float p_health = 100, float p_speed = 10, float p_mass = 10, stv::Vector2 p_velocity = stv::Vector2(0, 0), float p_jump = 10) {
			texture = p_texture;

			position = p_position;
			size = p_size;

			health = p_health;
			speed = p_speed;
			mass = p_speed;
			velocity = p_velocity;
			jump = p_jump;
		}

		Player(stv::Vector2 p_position, stv::Vector2 p_size, float p_health = 100, float p_speed = 10, float p_mass = 10, stv::Vector2 p_velocity = stv::Vector2(0, 0), float p_jump = 10) {
			position = p_position;
			size = p_size;

			health = p_health;
			speed = p_speed;
			mass = p_speed;
			velocity = p_velocity;
			jump = p_jump;
		}

		Player() {}

		void draw() {

		}

		void fastDraw(stv::rgb color) {
			geo::rectangle(position, size, color);
		}

	};

	void doGravity(Player player, std::vector<stv::object> grounds) {
		float y = player.position.y + player.size.y / 2;
		float x = player.position.x + player.size.x / 2;
		for (auto x : grounds) {
			if (x.position.y) {

			}
		}
	}
}