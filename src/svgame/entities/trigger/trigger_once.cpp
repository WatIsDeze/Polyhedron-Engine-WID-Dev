// LICENSE HERE.

//
// svgame/entities/trigger_once.c
//
//
// trigger_once entity implementation.
//

#include "../../g_local.h"      // SVGame funcs.
#include "../../utils.h"        // Util funcs.

#include "../../trigger.h"

// Extern in trigger_multiple.c
extern void SP_trigger_multiple(Entity* ent);

//=====================================================
/*QUAKED trigger_once (.5 .5 .5) ? x x TRIGGERED
Triggers once, then removes itself.
You must set the key "target" to the name of another object in the level that has a matching "targetName".

If TRIGGERED, this trigger must be triggered before it is live.

sounds
 1) secret
 2) beep beep
 3) large switch
 4)

"message"   string to be displayed when triggered
*/

void SP_trigger_once(Entity* ent)
{
    // make old maps work because I messed up on flag assignments here
    // triggered was on bit 1 when it should have been on bit 4
    if (ent->spawnFlags & 1) {
        vec3_t  v;

        VectorMA(ent->mins, 0.5, ent->size, v);
        ent->spawnFlags &= ~1;
        ent->spawnFlags |= 4;
        gi.DPrintf("fixed TRIGGERED flag on %s at %s\n", ent->className, Vec3ToString(v));
    }

    ent->wait = -1;
    SP_trigger_multiple(ent);
}