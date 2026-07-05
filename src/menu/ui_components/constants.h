/**
 * @file constants.h
 * @brief UI component layout and color constants for the menu system.
 * @ingroup ui_components
 *
 * This header defines all layout, sizing, and color constants used by UI components.
 */

#ifndef COMPONENTS_CONSTANTS_H__
#define COMPONENTS_CONSTANTS_H__

/**
 * @def TAB_HEIGHT
 * @brief Height of the tabs in the main menu (pixels).
 */
#define TAB_HEIGHT                      (20)

/**
 * @def BORDER_THICKNESS
 * @brief Thickness of UI borders (pixels).
 */
#define BORDER_THICKNESS                (4)

/**
 * @def DISPLAY_WIDTH
 * @brief Width of the display (pixels).
 */
#define DISPLAY_WIDTH                   (640)
/**
 * @def DISPLAY_HEIGHT
 * @brief Height of the display (pixels).
 */
#define DISPLAY_HEIGHT                  (480)

/**
 * @def DISPLAY_CENTER_X
 * @brief Center X coordinate of the display.
 */
#define DISPLAY_CENTER_X                (DISPLAY_WIDTH / 2)
/**
 * @def DISPLAY_CENTER_Y
 * @brief Center Y coordinate of the display.
 */
#define DISPLAY_CENTER_Y                (DISPLAY_HEIGHT / 2)

/**
 * @def OVERSCAN_WIDTH
 * @brief Overscan margin on the X axis (pixels).
 */
#define OVERSCAN_WIDTH                  (32)
/**
 * @def OVERSCAN_HEIGHT
 * @brief Overscan margin on the Y axis (pixels).
 */
#define OVERSCAN_HEIGHT                 (24)

/**
 * @def VISIBLE_AREA_X0
 * @brief Start X coordinate of the visible display area.
 */
#define VISIBLE_AREA_X0                 (OVERSCAN_WIDTH)
/**
 * @def VISIBLE_AREA_Y0
 * @brief Start Y coordinate of the visible display area.
 */
#define VISIBLE_AREA_Y0                 (OVERSCAN_HEIGHT)
/**
 * @def VISIBLE_AREA_X1
 * @brief End X coordinate of the visible display area.
 */
#define VISIBLE_AREA_X1                 (DISPLAY_WIDTH - OVERSCAN_WIDTH)
/**
 * @def VISIBLE_AREA_Y1
 * @brief End Y coordinate of the visible display area.
 */
#define VISIBLE_AREA_Y1                 (DISPLAY_HEIGHT - OVERSCAN_HEIGHT)

/**
 * @def VISIBLE_AREA_WIDTH
 * @brief Width of the visible display area (pixels).
 */
#define VISIBLE_AREA_WIDTH              (VISIBLE_AREA_X1 - VISIBLE_AREA_X0)
/**
 * @def VISIBLE_AREA_HEIGHT
 * @brief Height of the visible display area (pixels).
 */
#define VISIBLE_AREA_HEIGHT             (VISIBLE_AREA_Y1 - VISIBLE_AREA_Y0)

/**
 * @def LAYOUT_ACTIONS_SEPARATOR_Y
 * @brief Y coordinate for the layout actions separator.
 */
#define LAYOUT_ACTIONS_SEPARATOR_Y      (400)

/**
 * @def SEEKBAR_HEIGHT
 * @brief Height of the seek bar (pixels).
 */
#define SEEKBAR_HEIGHT                  (24)
/**
 * @def SEEKBAR_WIDTH
 * @brief Width of the seek bar (pixels).
 */
#define SEEKBAR_WIDTH                   (524)
/**
 * @def SEEKBAR_X
 * @brief X coordinate of the seek bar.
 */
#define SEEKBAR_X                       (DISPLAY_CENTER_X - (SEEKBAR_WIDTH / 2))
/**
 * @def SEEKBAR_Y
 * @brief Y coordinate of the seek bar.
 */
#define SEEKBAR_Y                       (VISIBLE_AREA_Y1 - SEEKBAR_HEIGHT - 80)

/**
 * @def LOADER_WIDTH
 * @brief Width of the loader bar (pixels).
 */
#define LOADER_WIDTH                    (320)
/**
 * @def LOADER_HEIGHT
 * @brief Height of the loader bar (pixels).
 */
#define LOADER_HEIGHT                   (24)
/**
 * @def LOADER_X
 * @brief X coordinate of the loader bar.
 */
#define LOADER_X                        (DISPLAY_CENTER_X - (LOADER_WIDTH / 2))
/**
 * @def LOADER_Y
 * @brief Y coordinate of the loader bar (accounts for message height).
 */
#define LOADER_Y                        (DISPLAY_CENTER_Y - (LOADER_HEIGHT / 2) - 8)

/**
 * @def MESSAGEBOX_MAX_WIDTH
 * @brief Maximum width of a message box (pixels).
 */
#define MESSAGEBOX_MAX_WIDTH            (360)
/**
 * @def MESSAGEBOX_MARGIN
 * @brief Margin around a message box (pixels).
 */
#define MESSAGEBOX_MARGIN               (32)

/**
 * @def TEXT_MARGIN_HORIZONTAL
 * @brief Horizontal margin for text (pixels).
 */
#define TEXT_MARGIN_HORIZONTAL          (10)
/**
 * @def TEXT_MARGIN_VERTICAL
 * @brief Vertical margin for text (pixels).
 */
#define TEXT_MARGIN_VERTICAL            (6)
/**
 * @def TEXT_OFFSET_VERTICAL
 * @brief Vertical offset for text (pixels).
 */
#define TEXT_OFFSET_VERTICAL            (1)
/**
 * @def TEXT_LINE_SPACING_ADJUST
 * @brief Adjustment for text line spacing (pixels).
 */
#define TEXT_LINE_SPACING_ADJUST        (0)

/**
 * @def BOXART_WIDTH
 * @brief Width of the boxart image (pixels).
 */
#define BOXART_WIDTH                    (158)
/**
 * @def BOXART_HEIGHT
 * @brief Height of the boxart image (pixels).
 */
#define BOXART_HEIGHT                   (112)

/**
 * @def BOXART_WIDTH_DD
 * @brief Width of the 64DD boxart image (pixels).
 */
#define BOXART_WIDTH_DD                 (129)
/**
 * @def BOXART_HEIGHT_DD
 * @brief Height of the 64DD boxart image (pixels).
 */
#define BOXART_HEIGHT_DD                (112)

/**
 * @def BOXART_WIDTH_MAX
 * @brief Maximum width of the boxart image (pixels).
 */
#define BOXART_WIDTH_MAX                (158)
/**
 * @def BOXART_HEIGHT_MAX
 * @brief Maximum height of the boxart image (pixels).
 */
#define BOXART_HEIGHT_MAX               (158)

/**
 * @def BOXART_X
 * @brief X coordinate for boxart image.
 */
#define BOXART_X                        (VISIBLE_AREA_X1 - BOXART_WIDTH - 24)
/**
 * @def BOXART_Y
 * @brief Y coordinate for boxart image.
 */
#define BOXART_Y                        (LAYOUT_ACTIONS_SEPARATOR_Y - BOXART_HEIGHT - 24)
/**
 * @def BOXART_X_JP
 * @brief X coordinate for Japanese boxart image.
 */
#define BOXART_X_JP                     (VISIBLE_AREA_X1 - BOXART_WIDTH_MAX + 21)
/**
 * @def BOXART_Y_JP
 * @brief Y coordinate for Japanese boxart image.
 */
#define BOXART_Y_JP                     (LAYOUT_ACTIONS_SEPARATOR_Y - BOXART_HEIGHT_MAX - 24)

/**
 * @def BOXART_X_DD
 * @brief X coordinate for 64DD boxart image.
 */
#define BOXART_X_DD                     (VISIBLE_AREA_X1 - BOXART_WIDTH_DD - 23)
/**
 * @def BOXART_Y_DD
 * @brief Y coordinate for 64DD boxart image.
 */
#define BOXART_Y_DD                     (LAYOUT_ACTIONS_SEPARATOR_Y - BOXART_HEIGHT_DD - 24)

/**
 * @def LIST_SCROLLBAR_WIDTH
 * @brief Width of the list scrollbar (pixels).
 */
#define LIST_SCROLLBAR_WIDTH            (12)
/**
 * @def LIST_SCROLLBAR_HEIGHT
 * @brief Height of the list scrollbar (pixels).
 */
#define LIST_SCROLLBAR_HEIGHT           (LAYOUT_ACTIONS_SEPARATOR_Y - OVERSCAN_HEIGHT - TAB_HEIGHT - BORDER_THICKNESS)
/**
 * @def LIST_SCROLLBAR_X
 * @brief X coordinate of the list scrollbar.
 */
#define LIST_SCROLLBAR_X                (VISIBLE_AREA_X1 - LIST_SCROLLBAR_WIDTH)
/**
 * @def LIST_SCROLLBAR_Y
 * @brief Y coordinate of the list scrollbar.
 */
#define LIST_SCROLLBAR_Y                (VISIBLE_AREA_Y0 + TAB_HEIGHT + BORDER_THICKNESS)

/**
 * @def LIST_ENTRIES
 * @brief Maximum number of file list entries.
 */
#define LIST_ENTRIES                    (19)
/**
 * @def FILE_LIST_MAX_WIDTH
 * @brief Maximum width for a file list entry (pixels).
 */
#define FILE_LIST_MAX_WIDTH             (480)
/**
 * @def FILE_LIST_HIGHLIGHT_WIDTH
 * @brief Width of the file list highlight (pixels).
 */
#define FILE_LIST_HIGHLIGHT_WIDTH       (VISIBLE_AREA_X1 - VISIBLE_AREA_X0 - LIST_SCROLLBAR_WIDTH)
/**
 * @def FILE_LIST_HIGHLIGHT_X
 * @brief X coordinate of the file list highlight.
 */
#define FILE_LIST_HIGHLIGHT_X           (VISIBLE_AREA_X0)

/**
 * Colors - Full Soft Pastel Theme
 */

// Backgrounds
#define BACKGROUND_EMPTY_COLOR          RGBA32(0xF8, 0xF4, 0xFF, 0xFF)  // Light lavender
#define BACKGROUND_OVERLAY_COLOR        RGBA32(0x20, 0x20, 0x35, 0xD0)  // Lighter dark overlay

// Borders
#define BORDER_COLOR                    RGBA32(0xC8, 0xB0, 0xE8, 0xFF)

// Progress / Scroll
#define PROGRESSBAR_BG_COLOR            RGBA32(0xE8, 0xE0, 0xF0, 0xFF)
#define PROGRESSBAR_DONE_COLOR          RGBA32(0xA0, 0xE0, 0xC8, 0xFF)

#define SCROLLBAR_BG_COLOR              RGBA32(0xE0, 0xE0, 0xF0, 0xFF)
#define SCROLLBAR_INACTIVE_COLOR        RGBA32(0xD0, 0xD0, 0xE8, 0xFF)
#define SCROLLBAR_POSITION_COLOR        RGBA32(0xB0, 0xD0, 0xFF, 0xFF)

// Dialogs & Highlights
#define DIALOG_BG_COLOR                 RGBA32(0xFF, 0xF8, 0xF8, 0xF0)
#define FILE_LIST_HIGHLIGHT_COLOR       RGBA32(0xE8, 0xD8, 0xFF, 0x88)
#define CONTEXT_MENU_HIGHLIGHT_COLOR    RGBA32(0xE0, 0xF0, 0xFF, 0x99)
#define BOXART_LOADING_COLOR            RGBA32(0xF0, 0xE8, 0xFF, 0xFF)

// Tabs
#define TAB_INACTIVE_BORDER_COLOR       RGBA32(0xD8, 0xC8, 0xE8, 0xFF)
#define TAB_ACTIVE_BORDER_COLOR         RGBA32(0xC0, 0xA8, 0xE0, 0xFF)
#define TAB_INACTIVE_BACKGROUND_COLOR   RGBA32(0xF0, 0xE8, 0xF8, 0xFF)
#define TAB_ACTIVE_BACKGROUND_COLOR     RGBA32(0xE0, 0xF0, 0xFF, 0xFF)

#endif /* COMPONENTS_CONSTANTS_H__ */
