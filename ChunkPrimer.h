#pragma once

#include "Utils.h"

#include <bitset>


struct ChunkPrimer {
public:
    std::bitset<65536> data{};

    constexpr static int getBlockIndex(int x, int y, int z) {
        return x << 12 | z << 8 | y;
    }
public:
    void setBlock(int x, int y, int z, bool solid) {
        data[getBlockIndex(x, y, z)] = solid;
    }

    bool isSolid(const BlockPos& pos) const {
        return isSolid(pos.x, pos.y, pos.z);
    }

    bool isSolid(int x, int y, int z) const {
        return data[getBlockIndex(x, y, z)];
    }
};