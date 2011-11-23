/*
 * Copyright (C) 2005-2008 MaNGOS <http://www.mangosproject.org/>
 *
 * Copyright (C) 2008 Trinity <http://www.trinitycore.org/>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
 */

#ifndef TRINITY_CONFUSEDGENERATOR_H
#define TRINITY_CONFUSEDGENERATOR_H

#include "MovementGenerator.h"
#include "DestinationHolder.h"
#include "Traveller.h"

#define WANDER_DISTANCE    2.5f
#define MAX_RANDOM_POINTS 6

template<class T>
class TRINITY_DLL_SPEC ConfusedMovementGenerator : public MovementGeneratorMedium< T, ConfusedMovementGenerator<T> >
{
    public:
        explicit ConfusedMovementGenerator() {}

        void Initialize(T &);
        void Finalize(T &);
        void Reset(T &);
        bool Update(T &, const uint32 &);

        bool GetDestination(float &x, float &y, float &z) const
        {
            if (i_destinationHolder.HasArrived())
                return false;

            i_destinationHolder.GetDestination(x,y,z);
            return true;
        }

        void GenerateMovement(T &unit);

        MovementGeneratorType GetMovementGeneratorType() { return CONFUSED_MOTION_TYPE; }

    private:

        Position randomPosition[MAX_RANDOM_POINTS+1];
        DestinationHolder< Traveller<T> > i_destinationHolder;
        uint32 i_nextMove;
};

#endif
