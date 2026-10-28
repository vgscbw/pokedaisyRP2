// Stand-in for pk_nds.h in builds without melonDS (PK_WITH_NDS not defined): the DS core is never built, so no DS cart
// is ever active and every call below does nothing. Keep the signatures in step with pk_nds.h.
#pragma once

#include <stdbool.h>
#include <stdint.h>

#include <android/native_window.h>

#define PK_NDS_W 256
#define PK_NDS_H 192

static inline bool pk_nds_is_rom(const char* path) { (void) path; return false; }
static inline bool pk_nds_init(const char* romPath, const char* savePath, int sampleRate) {
    (void) romPath; (void) savePath; (void) sampleRate; return false;
}
static inline void pk_nds_deinit(void) {}
static inline bool pk_nds_active(void) { return false; }

static inline void pk_nds_set_keys(uint32_t keys) { (void) keys; }
static inline void pk_nds_touch(bool down, int x, int y) { (void) down; (void) x; (void) y; }
static inline void pk_nds_run_frame(void) {}

static inline uint32_t* pk_nds_top(void) { return 0; }
static inline uint32_t* pk_nds_bottom(void) { return 0; }

static inline int pk_nds_read_audio(int16_t* out, int maxFrames) { (void) out; (void) maxFrames; return 0; }
static inline void pk_nds_set_audio_rate(double rate) { (void) rate; }

static inline bool pk_nds_flush_save(void) { return false; }
static inline int pk_nds_finish_save(int maxFrames) { (void) maxFrames; return 0; }

static inline bool pk_nds_save_state(const char* path) { (void) path; return false; }
static inline bool pk_nds_load_state(const char* path) { (void) path; return false; }
static inline int pk_nds_state_matches_save(const char* path) { (void) path; return -1; }

static inline void pk_nds_read(uint32_t addr, uint8_t* dst, int len) { (void) addr; (void) dst; (void) len; }
static inline bool pk_nds_write(uint32_t addr, const uint8_t* src, int len) {
    (void) addr; (void) src; (void) len; return false;
}

static inline int pk_nds_field_bits(void) { return 0; }
static inline int pk_nds_action(int action, const uint32_t args[4]) { (void) action; (void) args; return 0; }
static inline int pk_nds_action_status(int seq) { (void) seq; return -1; }
static inline bool pk_nds_action_results(int seq, uint32_t* out) { (void) seq; (void) out; return false; }
static inline void pk_nds_set_wild_off(bool off) { (void) off; }
static inline void pk_nds_set_wild_rates(const int32_t* triples, int n) { (void) triples; (void) n; }

static inline int pk_nds_bgm(void) { return -1; }
static inline bool pk_nds_bgm_fading(void) { return false; }
static inline bool pk_nds_music_start(void) { return false; }
static inline int pk_nds_music_read(int16_t* out, int maxFrames) { (void) out; (void) maxFrames; return 0; }
static inline void pk_nds_music_fade_out(int frames) { (void) frames; }
static inline void pk_nds_music_stop(void) {}

static inline void pk_nds_wide_enable(bool on) { (void) on; }
static inline void pk_nds_set_draw(bool draw, bool drawNext) { (void) draw; (void) drawNext; }
static inline bool pk_nds_frame_drawn(void) { return false; }
static inline bool pk_nds_wide_draw(uint32_t* out, int x, int y, int w, int h) {
    (void) out; (void) x; (void) y; (void) w; (void) h; return false;
}
static inline int pk_nds_wide_scene(void) { return 0; }
static inline void pk_nds_wide_window(int x, int y, int w, int h) { (void) x; (void) y; (void) w; (void) h; }

static inline bool pk_nds_rom_code(char out[5]) { (void) out; return false; }
static inline int pk_nds_rom_revision(void) { return 0; }
static inline uint32_t pk_nds_rom_size(void) { return 0; }
static inline const uint8_t* pk_nds_dtcm(void) { return 0; }

// DS RESOLUTION / the GPU path (pk_nds_gl): nothing to scale or present without a DS.
static inline void pk_nds_set_scale(int scale) { (void) scale; }
static inline int pk_nds_scale(void) { return 1; }
static inline int pk_nds_gpu_supported(void) { return 0; }
static inline bool pk_nds_presented(void) { return false; }
static inline bool pk_nds_gpu_frame_info(int64_t timestamp, int32_t out[6]) { (void) timestamp; (void) out; return false; }
// The real one takes over the caller's reference to the window, so this one gives it back.
static inline void pk_nds_set_window(struct ANativeWindow* window) { if (window) ANativeWindow_release(window); }
