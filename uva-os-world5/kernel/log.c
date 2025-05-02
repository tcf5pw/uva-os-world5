#include "utils.h"
#include "fs.h"

// Simple logging that allows concurrent FS system calls.
//
// A log transaction contains the updates of multiple FS system
// calls. The logging system only commits when there are
// no FS system calls active. Thus there is never
// any reasoning required about whether a commit might
// write an uncommitted system call's updates to disk. fxl: meaning??
//
// A system call should call begin_op()/end_op() to mark
// its start and end. Usually begin_op() just increments
// the count of in-progress FS system calls and returns.
// But if it thinks the log is close to running out, it
// sleeps until the last outstanding end_op() commits.
//
// The log is a physical re-do log containing disk blocks.
// The on-disk log format:
//   header block, containing block #s for block A, B, C, ...
//   block A
//   block B
//   block C
//   ...
// Log appends are synchronous.
// fxl: redo log seems an overkill... unless for teaching this concept specifically

void
initlog(int dev, struct superblock *sb)
{
  return; 
}

// called at the start of each FS system call.
// fxl: mostly handling sync issues: what if a committ is ongoing, insufficeint log space, etc.
void
begin_op(void)
{
  return; 
}

// called at the end of each FS system call.
// commits if this was the last outstanding operation.
void
end_op(void)
{
  return; 
}

// Caller has modified b->data and is done with the buffer.
// Record the block number and pin in the cache by increasing refcnt.
// commit()/write_log() will do the disk write.
//
// log_write() replaces bwrite(); a typical use is:
//   bp = bread(...)
//   modify bp->data[]
//   log_write(bp)
//   brelse(bp)
void
log_write(struct buf *b)
{
  bwrite(b); 
}

