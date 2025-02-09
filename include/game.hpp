#ifndef GAME_HPP
#define GAME_HPP

#include "config.hpp"
#include "gfx.hpp"
#include "kbd.hpp"

#include <string>
#include <vector>

class Game {
	Kbd _kbd;
	Config _config;
	time_t _today = time(NULL) / 24 / 60 / 60;
	std::u16string_view _answer;
	std::u16string _guess = u"";
	int _currentGuess = 0;
	int _popupTimeout = -1;
	bool _won = false;
	bool _statsSaved = false;
	bool _showRefresh = false;
	bool _bootstubExists;
	std::u16string _knownLetters, _knownPositions; // for hard mode

public:
	Game(void);

	~Game(void);

	void drawBgBottom(std::string_view msg, int timeout);
	std::vector<TilePalette> check(const std::u16string &guess);
	std::string shareMessage(void);
	bool run(void);

	const Config &config(void) const { return _config; }
};

#endif // GAME_HPP
