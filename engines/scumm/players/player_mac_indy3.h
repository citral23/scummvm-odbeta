/* ScummVM - Graphic Adventure Engine
 *
 * ScummVM is the legal property of its developers, whose names
 * are too numerous to list here. Please refer to the COPYRIGHT
 * file distributed with this source distribution.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

#ifndef SCUMM_PLAYERS_PLAYER_MAC_INDY3_H
#define SCUMM_PLAYERS_PLAYER_MAC_INDY3_H

#include "scumm/music.h"

namespace Audio {
class Mixer;
}

namespace Scumm {

class ScummEngine;
class I3MPlayer;

class Player_Mac_Indy3 : public MusicEngine {
public:
	enum Quality {
		kQualAuto = 0,
		kQualHi,
		kQualLo
	};

	Player_Mac_Indy3(ScummEngine *vm, Audio::Mixer *mixer);
	~Player_Mac_Indy3() override;
	void setMusicVolume(int vol) override;
	void setSfxVolume(int vol) override;
	void startSound(int id) override;
	void stopSound(int id) override;
	void stopAllSounds() override;
	int getMusicTimer() override;
	int getSoundStatus(int id) const override;
	void setQuality(int qual) override;
	void saveLoadWithSerializer(Common::Serializer &ser) override;
	void restoreAfterLoad() override;

private:
	Common::SharedPtr<I3MPlayer> _player;
};

} // End of namespace Scumm

#endif
