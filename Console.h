#pragma once

#include <string>
#include <vector>

namespace panda
{
	class Console
	{
	public:
		/// Creates a console abstraction
		Console();

		/// Starts drawing characters
		void begin();

		/// Ends drawing character
		void end();

		/// Clears the console
		/// Returns false if action failed
		bool clear();

		/// Returns the console width
		int width() const;

		/// Returns the console height
		int height() const;

		/// Draws the given string at row, column
		void draw(const std::string& str, int x, int y) const;

		/// Draws the given char at row, column
		void draw(char text, int x, int y) const;

		/// Draws a white rectangle at row, column
		void drawRect(int x, int y, int width, int heigth) const;

		/// Draws the given string, with a shade under it
		void drawRectBottomShaded(int x, int y, int width, int heigth) const;

		/// Draws a red rectangle with stripes
		void drawRectRedFancy(int x, int y, int width, int heigth) const;

		/// Draws a red rectangle with stripes, with a shade under it
		void drawRectRedFancyShaded(int x, int y, int width, int heigth) const;

		/// Draw a rectangle outline
		void drawRectOutline(int x, int y, int width, int height, int color = 0x0F, bool fill = true) const;

		/// Draw a rectangle outline, using the double character
		void drawCrosses(int x, int y, int width, int height, int color = 0x0F) const;

	private:
		void writeBuffer(const std::string& str) const;
		void writeBuffer(char c) const;

		bool setSize();
		bool setStyle();

		void setCursorPosition(int row, int column) const;

		void swapBuffers();

		void* m_firstBuffer = nullptr;
		void* m_secondBuffer = nullptr;
		void* m_backBuffer = nullptr;
		int m_width = 0;
		int m_height = 0;
	};
}