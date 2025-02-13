// NOTE: Assertions have been autogenerated by utils/update_cc_test_checks.py
//===- aie2-ldst.cpp --------------------------------------------*- C++ -*-===//
//
// This file is licensed under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
// (c) Copyright 2023-2024 Advanced Micro Devices, Inc. or its affiliates
//
//===----------------------------------------------------------------------===//
// RUN: %clang -O2 %s --target=aie2 -S -emit-llvm -o - | FileCheck %s

// CHECK-LABEL: @_Z9test_packDv32_si(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = tail call noundef <32 x i8> @llvm.aie2.pack.I8.I16(<32 x i16> [[V:%.*]], i32 [[SIGN:%.*]])
// CHECK-NEXT:    ret <32 x i8> [[TMP0]]
//
v32int8 test_pack(v32int16 v, int sign) {
  return pack(v, sign);
}

// CHECK-LABEL: @_Z25test_pack_double_v32int16Dv32_sPDv32_aS1_i(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    tail call void @llvm.aie2.set.ctrl.reg(i32 9, i32 0)
// CHECK-NEXT:    [[TMP0:%.*]] = tail call noundef <32 x i8> @llvm.aie2.pack.I8.I16(<32 x i16> [[V:%.*]], i32 [[SIGN:%.*]])
// CHECK-NEXT:    store <32 x i8> [[TMP0]], ptr [[P1:%.*]], align 32, !tbaa [[TBAA2:![0-9]+]]
// CHECK-NEXT:    store <32 x i8> [[TMP0]], ptr [[P2:%.*]], align 32, !tbaa [[TBAA2]]
// CHECK-NEXT:    ret void
//
void test_pack_double_v32int16 (v32int16 v, v32int8 *p1, v32int8 *p2, int sign) {
  set_satmode(0);
  p1[0] = pack(v, sign);
  p2[0] = pack(v, sign);
}

// CHECK-LABEL: @_Z22test_pack_sat_v32int16Dv32_sPDv32_aS1_i(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    tail call void @llvm.aie2.set.ctrl.reg(i32 9, i32 0)
// CHECK-NEXT:    [[TMP0:%.*]] = tail call noundef <32 x i8> @llvm.aie2.pack.I8.I16(<32 x i16> [[V:%.*]], i32 [[SIGN:%.*]])
// CHECK-NEXT:    store <32 x i8> [[TMP0]], ptr [[P1:%.*]], align 32, !tbaa [[TBAA2]]
// CHECK-NEXT:    tail call void @llvm.aie2.set.ctrl.reg(i32 9, i32 1)
// CHECK-NEXT:    [[TMP1:%.*]] = tail call noundef <32 x i8> @llvm.aie2.pack.I8.I16(<32 x i16> [[V]], i32 [[SIGN]])
// CHECK-NEXT:    store <32 x i8> [[TMP1]], ptr [[P2:%.*]], align 32, !tbaa [[TBAA2]]
// CHECK-NEXT:    ret void
//
void test_pack_sat_v32int16 (v32int16 v, v32int8 *p1, v32int8 *p2, int sign) {
  set_satmode(0);
  p1[0] = pack(v, sign);
  set_satmode(1);
  p2[0] = pack(v, sign);
}

// CHECK-LABEL: @_Z9test_packDv32_ti(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = tail call noundef <32 x i8> @llvm.aie2.pack.I8.I16(<32 x i16> [[V:%.*]], i32 [[SIGN:%.*]])
// CHECK-NEXT:    ret <32 x i8> [[TMP0]]
//
v32uint8 test_pack(v32uint16 v, int sign) {
  return pack(v, sign);
}

// CHECK-LABEL: @_Z23test_pack_sat_v32uint16Dv32_tPDv32_hS1_i(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    tail call void @llvm.aie2.set.ctrl.reg(i32 9, i32 1)
// CHECK-NEXT:    [[TMP0:%.*]] = tail call noundef <32 x i8> @llvm.aie2.pack.I8.I16(<32 x i16> [[V:%.*]], i32 [[SIGN:%.*]])
// CHECK-NEXT:    store <32 x i8> [[TMP0]], ptr [[P1:%.*]], align 32, !tbaa [[TBAA2]]
// CHECK-NEXT:    tail call void @llvm.aie2.set.ctrl.reg(i32 9, i32 0)
// CHECK-NEXT:    [[TMP1:%.*]] = tail call noundef <32 x i8> @llvm.aie2.pack.I8.I16(<32 x i16> [[V]], i32 [[SIGN]])
// CHECK-NEXT:    store <32 x i8> [[TMP1]], ptr [[P2:%.*]], align 32, !tbaa [[TBAA2]]
// CHECK-NEXT:    ret void
//
void test_pack_sat_v32uint16 (v32uint16 v, v32uint8 *p1, v32uint8 *p2, int sign) {
  set_satmode(1);
  p1[0] = pack(v, sign);
  set_satmode(0);
  p2[0] = pack(v, sign);
}

// CHECK-LABEL: @_Z9test_packDv64_ai(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = bitcast <64 x i8> [[V:%.*]] to <32 x i16>
// CHECK-NEXT:    [[TMP1:%.*]] = tail call noundef <32 x i8> @llvm.aie2.pack.I4.I8(<32 x i16> [[TMP0]], i32 [[SIGN:%.*]])
// CHECK-NEXT:    ret <32 x i8> [[TMP1]]
//
v64int4 test_pack(v64int8 v, int sign) {
  return pack(v, sign);
}

// CHECK-LABEL: @_Z21test_pack_sat_v64int8Dv64_aPDv32_DB8_S2_i(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    tail call void @llvm.aie2.set.ctrl.reg(i32 9, i32 1)
// CHECK-NEXT:    [[TMP0:%.*]] = bitcast <64 x i8> [[V:%.*]] to <32 x i16>
// CHECK-NEXT:    [[TMP1:%.*]] = tail call noundef <32 x i8> @llvm.aie2.pack.I4.I8(<32 x i16> [[TMP0]], i32 [[SIGN:%.*]])
// CHECK-NEXT:    store <32 x i8> [[TMP1]], ptr [[P1:%.*]], align 32, !tbaa [[TBAA2]]
// CHECK-NEXT:    tail call void @llvm.aie2.set.ctrl.reg(i32 9, i32 0)
// CHECK-NEXT:    [[TMP2:%.*]] = tail call noundef <32 x i8> @llvm.aie2.pack.I4.I8(<32 x i16> [[TMP0]], i32 [[SIGN]])
// CHECK-NEXT:    store <32 x i8> [[TMP2]], ptr [[P2:%.*]], align 32, !tbaa [[TBAA2]]
// CHECK-NEXT:    ret void
//
void test_pack_sat_v64int8 (v64int8 v, v64int4 *p1, v64int4 *p2, int sign) {
  set_satmode(1);
  p1[0] = pack(v, sign);
  set_satmode(0);
  p2[0] = pack(v, sign);
}

// CHECK-LABEL: @_Z9test_packDv64_hi(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = bitcast <64 x i8> [[V:%.*]] to <32 x i16>
// CHECK-NEXT:    [[TMP1:%.*]] = tail call noundef <32 x i8> @llvm.aie2.pack.I4.I8(<32 x i16> [[TMP0]], i32 [[SIGN:%.*]])
// CHECK-NEXT:    ret <32 x i8> [[TMP1]]
//
v64uint4 test_pack(v64uint8 v, int sign) {
  return pack(v, sign);
}

// CHECK-LABEL: @_Z22test_pack_sat_v64uint8Dv64_hPDv32_DU8_S2_i(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    tail call void @llvm.aie2.set.ctrl.reg(i32 9, i32 0)
// CHECK-NEXT:    [[TMP0:%.*]] = bitcast <64 x i8> [[V:%.*]] to <32 x i16>
// CHECK-NEXT:    [[TMP1:%.*]] = tail call noundef <32 x i8> @llvm.aie2.pack.I4.I8(<32 x i16> [[TMP0]], i32 [[SIGN:%.*]])
// CHECK-NEXT:    store <32 x i8> [[TMP1]], ptr [[P1:%.*]], align 32, !tbaa [[TBAA2]]
// CHECK-NEXT:    tail call void @llvm.aie2.set.ctrl.reg(i32 9, i32 1)
// CHECK-NEXT:    [[TMP2:%.*]] = tail call noundef <32 x i8> @llvm.aie2.pack.I4.I8(<32 x i16> [[TMP0]], i32 [[SIGN]])
// CHECK-NEXT:    store <32 x i8> [[TMP2]], ptr [[P2:%.*]], align 32, !tbaa [[TBAA2]]
// CHECK-NEXT:    ret void
//
void test_pack_sat_v64uint8 (v64uint8 v, v64uint4 *p1, v64uint4 *p2, int sign) {
  set_satmode(0);
  p1[0] = pack(v, sign);
  set_satmode(1);
  p2[0] = pack(v, sign);
}

// CHECK-LABEL: @_Z9test_packDv32_s(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = tail call noundef <32 x i8> @llvm.aie2.pack.I8.I16(<32 x i16> [[V:%.*]], i32 1)
// CHECK-NEXT:    ret <32 x i8> [[TMP0]]
//
v32int8 test_pack(v32int16 v) {
  return pack(v);
}

// CHECK-LABEL: @_Z22test_pack_sat_v32int16Dv32_sPDv32_aS1_(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    tail call void @llvm.aie2.set.ctrl.reg(i32 9, i32 0)
// CHECK-NEXT:    [[TMP0:%.*]] = tail call noundef <32 x i8> @llvm.aie2.pack.I8.I16(<32 x i16> [[V:%.*]], i32 1)
// CHECK-NEXT:    store <32 x i8> [[TMP0]], ptr [[P1:%.*]], align 32, !tbaa [[TBAA2]]
// CHECK-NEXT:    tail call void @llvm.aie2.set.ctrl.reg(i32 9, i32 1)
// CHECK-NEXT:    [[TMP1:%.*]] = tail call noundef <32 x i8> @llvm.aie2.pack.I8.I16(<32 x i16> [[V]], i32 1)
// CHECK-NEXT:    store <32 x i8> [[TMP1]], ptr [[P2:%.*]], align 32, !tbaa [[TBAA2]]
// CHECK-NEXT:    ret void
//
void test_pack_sat_v32int16 (v32int16 v, v32int8 *p1, v32int8 *p2) {
  set_satmode(0);
  p1[0] = pack(v);
  set_satmode(1);
  p2[0] = pack(v);
}

// CHECK-LABEL: @_Z9test_packDv32_t(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = tail call noundef <32 x i8> @llvm.aie2.pack.I8.I16(<32 x i16> [[V:%.*]], i32 0)
// CHECK-NEXT:    ret <32 x i8> [[TMP0]]
//
v32uint8 test_pack(v32uint16 v) {
  return pack(v);
}

// CHECK-LABEL: @_Z23test_pack_sat_v32uint16Dv32_tPDv32_hS1_(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    tail call void @llvm.aie2.set.ctrl.reg(i32 9, i32 1)
// CHECK-NEXT:    [[TMP0:%.*]] = tail call noundef <32 x i8> @llvm.aie2.pack.I8.I16(<32 x i16> [[V:%.*]], i32 0)
// CHECK-NEXT:    store <32 x i8> [[TMP0]], ptr [[P1:%.*]], align 32, !tbaa [[TBAA2]]
// CHECK-NEXT:    tail call void @llvm.aie2.set.ctrl.reg(i32 9, i32 0)
// CHECK-NEXT:    [[TMP1:%.*]] = tail call noundef <32 x i8> @llvm.aie2.pack.I8.I16(<32 x i16> [[V]], i32 0)
// CHECK-NEXT:    store <32 x i8> [[TMP1]], ptr [[P2:%.*]], align 32, !tbaa [[TBAA2]]
// CHECK-NEXT:    ret void
//
void test_pack_sat_v32uint16 (v32uint16 v, v32uint8 *p1, v32uint8 *p2) {
  set_satmode(1);
  p1[0] = pack(v);
  set_satmode(0);
  p2[0] = pack(v);
}

// CHECK-LABEL: @_Z9test_packDv64_a(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = bitcast <64 x i8> [[V:%.*]] to <32 x i16>
// CHECK-NEXT:    [[TMP1:%.*]] = tail call noundef <32 x i8> @llvm.aie2.pack.I4.I8(<32 x i16> [[TMP0]], i32 1)
// CHECK-NEXT:    ret <32 x i8> [[TMP1]]
//
v64int4 test_pack(v64int8 v) {
  return pack(v);
}

// CHECK-LABEL: @_Z21test_pack_sat_v64int8Dv64_aPDv32_DB8_S2_(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    tail call void @llvm.aie2.set.ctrl.reg(i32 9, i32 0)
// CHECK-NEXT:    [[TMP0:%.*]] = bitcast <64 x i8> [[V:%.*]] to <32 x i16>
// CHECK-NEXT:    [[TMP1:%.*]] = tail call noundef <32 x i8> @llvm.aie2.pack.I4.I8(<32 x i16> [[TMP0]], i32 1)
// CHECK-NEXT:    store <32 x i8> [[TMP1]], ptr [[P1:%.*]], align 32, !tbaa [[TBAA2]]
// CHECK-NEXT:    tail call void @llvm.aie2.set.ctrl.reg(i32 9, i32 1)
// CHECK-NEXT:    [[TMP2:%.*]] = tail call noundef <32 x i8> @llvm.aie2.pack.I4.I8(<32 x i16> [[TMP0]], i32 1)
// CHECK-NEXT:    store <32 x i8> [[TMP2]], ptr [[P2:%.*]], align 32, !tbaa [[TBAA2]]
// CHECK-NEXT:    ret void
//
void test_pack_sat_v64int8 (v64int8 v, v64int4 *p1, v64int4 *p2) {
  set_satmode(0);
  p1[0] = pack(v);
  set_satmode(1);
  p2[0] = pack(v);
}

// CHECK-LABEL: @_Z24test_pack_double_v64int8Dv64_aPDv32_DB8_S2_(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    tail call void @llvm.aie2.set.ctrl.reg(i32 9, i32 1)
// CHECK-NEXT:    [[TMP0:%.*]] = bitcast <64 x i8> [[V:%.*]] to <32 x i16>
// CHECK-NEXT:    [[TMP1:%.*]] = tail call noundef <32 x i8> @llvm.aie2.pack.I4.I8(<32 x i16> [[TMP0]], i32 1)
// CHECK-NEXT:    store <32 x i8> [[TMP1]], ptr [[P1:%.*]], align 32, !tbaa [[TBAA2]]
// CHECK-NEXT:    store <32 x i8> [[TMP1]], ptr [[P2:%.*]], align 32, !tbaa [[TBAA2]]
// CHECK-NEXT:    ret void
//
void test_pack_double_v64int8 (v64int8 v, v64int4 *p1, v64int4 *p2) {
  set_satmode(1);
  p1[0] = pack(v);
  p2[0] = pack(v);
}

// CHECK-LABEL: @_Z9test_packDv64_h(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = bitcast <64 x i8> [[V:%.*]] to <32 x i16>
// CHECK-NEXT:    [[TMP1:%.*]] = tail call noundef <32 x i8> @llvm.aie2.pack.I4.I8(<32 x i16> [[TMP0]], i32 0)
// CHECK-NEXT:    ret <32 x i8> [[TMP1]]
//
v64uint4 test_pack(v64uint8 v) {
  return pack(v);
}

// CHECK-LABEL: @_Z22test_pack_sat_v64uint8Dv64_hPDv32_DU8_S2_(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    tail call void @llvm.aie2.set.ctrl.reg(i32 9, i32 0)
// CHECK-NEXT:    [[TMP0:%.*]] = bitcast <64 x i8> [[V:%.*]] to <32 x i16>
// CHECK-NEXT:    [[TMP1:%.*]] = tail call noundef <32 x i8> @llvm.aie2.pack.I4.I8(<32 x i16> [[TMP0]], i32 0)
// CHECK-NEXT:    store <32 x i8> [[TMP1]], ptr [[P1:%.*]], align 32, !tbaa [[TBAA2]]
// CHECK-NEXT:    tail call void @llvm.aie2.set.ctrl.reg(i32 9, i32 1)
// CHECK-NEXT:    [[TMP2:%.*]] = tail call noundef <32 x i8> @llvm.aie2.pack.I4.I8(<32 x i16> [[TMP0]], i32 0)
// CHECK-NEXT:    store <32 x i8> [[TMP2]], ptr [[P2:%.*]], align 32, !tbaa [[TBAA2]]
// CHECK-NEXT:    ret void
//
void test_pack_sat_v64uint8 (v64uint8 v, v64uint4 *p1, v64uint4 *p2) {
  set_satmode(0);
  p1[0] = pack(v);
  set_satmode(1);
  p2[0] = pack(v);
}

// CHECK-LABEL: @_Z11test_unpackDv32_ab(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[CONV_I:%.*]] = zext i1 [[SIGN:%.*]] to i32
// CHECK-NEXT:    [[TMP0:%.*]] = tail call noundef <32 x i16> @llvm.aie2.unpack.I16.I8(<32 x i8> [[V:%.*]], i32 [[CONV_I]])
// CHECK-NEXT:    ret <32 x i16> [[TMP0]]
//
v32int16 test_unpack(v32int8 v, bool sign) {
  return unpack(v, sign);
}

// CHECK-LABEL: @_Z11test_unpackDv32_hb(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[CONV_I:%.*]] = zext i1 [[SIGN:%.*]] to i32
// CHECK-NEXT:    [[TMP0:%.*]] = tail call noundef <32 x i16> @llvm.aie2.unpack.I16.I8(<32 x i8> [[V:%.*]], i32 [[CONV_I]])
// CHECK-NEXT:    ret <32 x i16> [[TMP0]]
//
v32uint16 test_unpack(v32uint8 v, bool sign) {
  return unpack(v, sign);
}

// CHECK-LABEL: @_Z11test_unpackDv32_DB8_b(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[CONV_I:%.*]] = zext i1 [[SIGN:%.*]] to i32
// CHECK-NEXT:    [[TMP0:%.*]] = tail call <32 x i16> @llvm.aie2.unpack.I8.I4(<32 x i8> [[V:%.*]], i32 [[CONV_I]])
// CHECK-NEXT:    [[TMP1:%.*]] = bitcast <32 x i16> [[TMP0]] to <64 x i8>
// CHECK-NEXT:    ret <64 x i8> [[TMP1]]
//
v64int8 test_unpack(v64int4 v, bool sign) {
  return unpack(v, sign);
}

// CHECK-LABEL: @_Z11test_unpackDv32_DU8_b(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[CONV_I:%.*]] = zext i1 [[SIGN:%.*]] to i32
// CHECK-NEXT:    [[TMP0:%.*]] = tail call <32 x i16> @llvm.aie2.unpack.I8.I4(<32 x i8> [[V:%.*]], i32 [[CONV_I]])
// CHECK-NEXT:    [[TMP1:%.*]] = bitcast <32 x i16> [[TMP0]] to <64 x i8>
// CHECK-NEXT:    ret <64 x i8> [[TMP1]]
//
v64uint8 test_unpack(v64uint4 v, bool sign) {
  return unpack(v, sign);
}

// CHECK-LABEL: @_Z11test_unpackDv32_a(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = tail call noundef <32 x i16> @llvm.aie2.unpack.I16.I8(<32 x i8> [[V:%.*]], i32 1)
// CHECK-NEXT:    ret <32 x i16> [[TMP0]]
//
v32int16 test_unpack(v32int8 v) {
  return unpack(v);
}

// CHECK-LABEL: @_Z11test_unpackDv32_h(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = tail call noundef <32 x i16> @llvm.aie2.unpack.I16.I8(<32 x i8> [[V:%.*]], i32 0)
// CHECK-NEXT:    ret <32 x i16> [[TMP0]]
//
v32uint16 test_unpack(v32uint8 v) {
  return unpack(v);
}

// CHECK-LABEL: @_Z11test_unpackDv32_DB8_(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = tail call <32 x i16> @llvm.aie2.unpack.I8.I4(<32 x i8> [[V:%.*]], i32 1)
// CHECK-NEXT:    [[TMP1:%.*]] = bitcast <32 x i16> [[TMP0]] to <64 x i8>
// CHECK-NEXT:    ret <64 x i8> [[TMP1]]
//
v64int8 test_unpack(v64int4 v) {
  return unpack(v);
}

// CHECK-LABEL: @_Z11test_unpackDv32_DU8_(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = tail call <32 x i16> @llvm.aie2.unpack.I8.I4(<32 x i8> [[V:%.*]], i32 0)
// CHECK-NEXT:    [[TMP1:%.*]] = bitcast <32 x i16> [[TMP0]] to <64 x i8>
// CHECK-NEXT:    ret <64 x i8> [[TMP1]]
//
v64uint8 test_unpack(v64uint4 v) {
  return unpack(v);
}
