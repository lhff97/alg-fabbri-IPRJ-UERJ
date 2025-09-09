/* R. Fabbri, 2024 */
#include "sorted_merge_3way.h"
#include <climits>

bool
sorted_merge_3way(
    const int *list_a, int na,
    const int *list_b, int nb,
    const int *list_c, int nc,
    int *list_abc)
{

    if (!is_sorted(a, na) || !is_sorted(b, nb) || !is_sorted(c, nc)) {
        return false;
    }

    int ia = 0, ib = 0, ic = 0, iabc = 0;

    while (ia < na || ib < nb || ic < nc) {
        int current_min = 2147483647;
        int min_source = -1;

        if (ia < na) {
            current_min = a[ia];
            min_source = 0;
        }
        if (ib < nb && b[ib] < current_min) {
            current_min = b[ib];
            min_source = 1;
        }
        if (ic < nc && c[ic] < current_min) {
            current_min = c[ic];
            min_source = 2;
        }

        abc[iabc++] = current_min;

        if (min_source == 0) {
            ia++;
        } else if (min_source == 1) {
            ib++;
        } else {
            ic++;
        }
    }

    return true;
}

