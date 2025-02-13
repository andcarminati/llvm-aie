// NOTE: Assertions have been autogenerated by utils/update_cc_test_checks.py
//===- aie2-locks.cpp -------------------------------------------*- C++ -*-===//
//
// This file is licensed under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
// (c) Copyright 2023-2024 Advanced Micro Devices, Inc. or its affiliates
//
//===----------------------------------------------------------------------===//
// RUN: %clang -O2 --target=aie2 -S -emit-llvm %s -o - | FileCheck %s

//
// CHECK-LABEL: @_Z18test_acquire_equaljj(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    tail call void @llvm.aie2.acquire(i32 [[ID:%.*]], i32 [[VAL:%.*]])
// CHECK-NEXT:    ret void
//
void test_acquire_equal(unsigned id, unsigned val) {
    acquire_equal(id, val);
}

// CHECK-LABEL: @_Z23test_acquire_equal_condjji(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    tail call void @llvm.aie2.acquire.cond(i32 [[ID:%.*]], i32 [[VAL:%.*]], i32 [[COND:%.*]])
// CHECK-NEXT:    ret void
//
void test_acquire_equal_cond(unsigned id, unsigned val, int cond) {
    acquire_equal(id, val, cond);
}

// CHECK-LABEL: @_Z18test_acquire_equalPKvjj(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    tail call void @llvm.aie2.acquire(i32 [[ID:%.*]], i32 [[VAL:%.*]])
// CHECK-NEXT:    ret void
//
void test_acquire_equal(const void * a, unsigned id, unsigned val) {
  acquire_equal(a, id, val);
}

// CHECK-LABEL: @_Z23test_acquire_equal_condPKvjji(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    tail call void @llvm.aie2.acquire.cond(i32 [[ID:%.*]], i32 [[VAL:%.*]], i32 [[COND:%.*]])
// CHECK-NEXT:    ret void
//
void test_acquire_equal_cond(const void * a, unsigned id, unsigned val, int cond) {
  acquire_equal(a, id, val, cond);
}

// CHECK-LABEL: @_Z26test_acquire_greater_equaljj(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[SUB_I:%.*]] = sub i32 0, [[VAL:%.*]]
// CHECK-NEXT:    tail call void @llvm.aie2.acquire(i32 [[ID:%.*]], i32 [[SUB_I]])
// CHECK-NEXT:    ret void
//
void test_acquire_greater_equal(unsigned id, unsigned val) {
    acquire_greater_equal(id, val);
}

// CHECK-LABEL: @_Z31test_acquire_greater_equal_condjji(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[SUB_I:%.*]] = sub i32 0, [[VAL:%.*]]
// CHECK-NEXT:    tail call void @llvm.aie2.acquire.cond(i32 [[ID:%.*]], i32 [[SUB_I]], i32 [[COND:%.*]])
// CHECK-NEXT:    ret void
//
void test_acquire_greater_equal_cond(unsigned id, unsigned val, int cond) {
    acquire_greater_equal(id, val, cond);
}

// CHECK-LABEL: @_Z26test_acquire_greater_equalPKvjj(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[SUB_I_I:%.*]] = sub i32 0, [[VAL:%.*]]
// CHECK-NEXT:    tail call void @llvm.aie2.acquire(i32 [[ID:%.*]], i32 [[SUB_I_I]])
// CHECK-NEXT:    ret void
//
void test_acquire_greater_equal(const void * a, unsigned id, unsigned val) {
  acquire_greater_equal(a, id, val);
}

// CHECK-LABEL: @_Z31test_acquire_greater_equal_condPKvjjj(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[SUB_I_I:%.*]] = sub i32 0, [[VAL:%.*]]
// CHECK-NEXT:    tail call void @llvm.aie2.acquire.cond(i32 [[ID:%.*]], i32 [[SUB_I_I]], i32 [[COND:%.*]])
// CHECK-NEXT:    ret void
//
void test_acquire_greater_equal_cond(const void * a, unsigned id, unsigned val, unsigned cond) {
  acquire_greater_equal(a, id, val, cond);
}

// CHECK-LABEL: @_Z12test_releaseji(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    tail call void @llvm.aie2.release(i32 [[ID:%.*]], i32 [[VAL:%.*]])
// CHECK-NEXT:    ret void
//
void test_release(unsigned id, int val) {
    release(id, val);
}

// CHECK-LABEL: @_Z17test_release_condjii(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    tail call void @llvm.aie2.release.cond(i32 [[ID:%.*]], i32 [[VAL:%.*]], i32 [[COND:%.*]])
// CHECK-NEXT:    ret void
//
void test_release_cond(unsigned id, int val, int cond) {
    release(id, val, cond);
}

// CHECK-LABEL: @_Z12test_releasePvji(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    tail call void @llvm.aie2.release(i32 [[ID:%.*]], i32 [[VAL:%.*]])
// CHECK-NEXT:    ret void
//
void test_release(void * a, unsigned id, int val) {
  release(a, id, val);
}

// CHECK-LABEL: @_Z17test_release_condPvjii(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    tail call void @llvm.aie2.release.cond(i32 [[ID:%.*]], i32 [[VAL:%.*]], i32 [[COND:%.*]])
// CHECK-NEXT:    ret void
//
void test_release_cond(void * a, unsigned id, int val, int cond) {
  release(a, id, val, cond);
}

// CHECK-LABEL: @_Z9test_donev(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    tail call void @llvm.aie2.sched.barrier()
// CHECK-NEXT:    tail call void @llvm.aie2.done()
// CHECK-NEXT:    tail call void @llvm.aie2.sched.barrier()
// CHECK-NEXT:    ret void
//
void test_done(void) {
    done();
}
