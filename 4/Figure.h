#pragma once

#include <cmath>
#include <iostream>
#include <vector>
#include <string>


#include "IGeoFig.h"
#include "CVector2D.h"
#include "IPhysObject.h"
#include "IPrintable.h"
#include "IDialogInitiable.h"
#include "BaseCObject.h"


class Figure :
        public IGeoFig,
        public IPhysObject,
        public IPrintable,
        public IDialogueInitiable,
        public BaseCObject,
        public CVector2D {
};
