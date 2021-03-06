## CS333 Project 1 - Individual Work in C

### Tyler Hansen

#### Part I: Coding in C

##### Task 1:

Creating an executable from `memoryaccess.c` called `exec_memoryaccess`, run the command `./exec_memoryaccess` and find the following:

```
Integer Loop:
0: 67
1: 45
2: 23
3: 01
Double Loop:
0: F7
1: 06
2: 5F
3: 98
4: 6C
5: 92
6: B0
7: 40
Short Loop:
0: FF
1: 7F
Long Loop:
0: 92
1: 10
2: 00
3: 00
4: 00
5: 00
6: 00
7: 00
Float Loop:
0: 5C
1: 93
2: 84
3: 45
Character Loop:
0: 63
```

From this, we can fill in the following table:
| Variable Type | Number of Bytes Allocated in Memory |
| ----------- | ----------- |
| Integer | 4 |
| Double | 8 |
| Short | 2 |
| Long | 8 |
| Float | 4 |
| Character | 1 |

We also note that the machine I am using is **(a)** little-endian, and we know this because **(b)** the "little end" (least significant value in the sequence) is stored first. The easiest way to see this is by looking at the results of the integer loop; the selected integer makes it readily apparent.

##### Task 2:

Creating an executable from `memoryaccess.c`, one finds that the output of this executable is the following (**PLEASE feel free to scroll past this ridiculously long code block**):

```
0: 98
1: 08
2: 60
3: E2
4: FE
5: 7F
6: 00
7: 00
8: F7
9: 06
10: 5F
11: 98
12: 6C
13: 92
14: B0
15: 40
16: 00
17: 00
18: 00
19: 00
20: 5C
21: 93
22: 84
23: 45
24: 92
25: 10
26: 00
27: 00
28: 00
29: 00
30: 00
31: 00
32: 67
33: 45
34: 23
35: 01
36: 00
37: 00
38: FF
39: 7F
40: F8
41: 08
42: 60
43: E2
44: FE
45: 7F
46: 00
47: 00
48: 01
49: 00
50: 00
51: 00
52: 00
53: 00
54: 00
55: 00
56: E8
57: 08
58: 60
59: E2
60: FE
61: 7F
62: 00
63: 00
64: 21
65: C6
66: 36
67: 20
68: FF
69: 7F
70: 00
71: 00
72: 21
73: C6
74: 36
75: 20
76: FF
77: 7F
78: 00
79: 00
80: 00
81: 00
82: 00
83: 00
84: 00
85: 00
86: 00
87: 00
88: 01
89: 00
90: 00
91: 00
92: 00
93: 00
94: 00
95: 00
96: 50
97: 0A
98: 60
99: E2
100: FE
101: 7F
102: 00
103: 00
104: 00
105: 00
106: 00
107: 00
108: 00
109: 00
110: 00
111: 00
112: 66
113: 0A
114: 60
115: E2
116: FE
117: 7F
118: 00
119: 00
120: A3
121: 0A
122: 60
123: E2
124: FE
125: 7F
126: 00
127: 00
128: CF
129: 0A
130: 60
131: E2
132: FE
133: 7F
134: 00
135: 00
136: EB
137: 0A
138: 60
139: E2
140: FE
141: 7F
142: 00
143: 00
144: FF
145: 0A
146: 60
147: E2
148: FE
149: 7F
150: 00
151: 00
152: 0F
153: 0B
154: 60
155: E2
156: FE
157: 7F
158: 00
159: 00
160: 48
161: 0B
162: 60
163: E2
164: FE
165: 7F
166: 00
167: 00
168: 61
169: 0B
170: 60
171: E2
172: FE
173: 7F
174: 00
175: 00
176: 96
177: 0B
178: 60
179: E2
180: FE
181: 7F
182: 00
183: 00
184: A1
185: 0B
186: 60
187: E2
188: FE
189: 7F
190: 00
191: 00
192: E3
193: 0B
194: 60
195: E2
196: FE
197: 7F
198: 00
199: 00
200: 09
201: 0C
202: 60
203: E2
204: FE
205: 7F
206: 00
207: 00
208: 39
209: 0C
210: 60
211: E2
212: FE
213: 7F
214: 00
215: 00
216: 6D
217: 0D
218: 60
219: E2
220: FE
221: 7F
222: 00
223: 00
224: A2
225: 0D
226: 60
227: E2
228: FE
229: 7F
230: 00
231: 00
232: D8
233: 0D
234: 60
235: E2
236: FE
237: 7F
238: 00
239: 00
240: 00
241: 0E
242: 60
243: E2
244: FE
245: 7F
246: 00
247: 00
248: 44
249: 0E
250: 60
251: E2
252: FE
253: 7F
254: 00
255: 00
256: 60
257: 59
258: 40
259: BA
260: 9C
261: 7F
262: 00
263: 00
264: 63
265: 0E
266: 60
267: E2
268: FE
269: 7F
270: 00
271: 00
272: 76
273: 0E
274: 60
275: E2
276: FE
277: 7F
278: 00
279: 00
280: 88
281: 0E
282: 60
283: E2
284: FE
285: 7F
286: 00
287: 00
288: 90
289: 0E
290: 60
291: E2
292: FE
293: 7F
294: 00
295: 00
296: 9E
297: 0E
298: 60
299: E2
300: FE
301: 7F
302: 00
303: 00
304: BC
305: 0E
306: 60
307: E2
308: FE
309: 7F
310: 00
311: 00
312: D4
313: 0E
314: 60
315: E2
316: FE
317: 7F
318: 00
319: 00
320: 00
321: 00
322: 00
323: 00
324: 00
325: 00
326: 00
327: 00
328: 28
329: 0A
330: 60
331: E2
332: FE
333: 7F
334: 00
335: 00
336: F0
337: 0E
338: 60
339: E2
340: FE
341: 7F
342: 00
343: 00
344: 03
345: 0F
346: 60
347: E2
348: FE
349: 7F
350: 00
351: 00
352: 22
353: 0F
354: 60
355: E2
356: FE
357: 7F
358: 00
359: 00
360: 56
361: 0F
362: 60
363: E2
364: FE
365: 7F
366: 00
367: 00
368: 73
369: 0F
370: 60
371: E2
372: FE
373: 7F
374: 00
375: 00
376: AF
377: 0F
378: 60
379: E2
380: FE
381: 7F
382: 00
383: 00
384: D1
385: 0F
386: 60
387: E2
388: FE
389: 7F
390: 00
391: 00
392: 00
393: 00
394: 00
395: 00
396: 00
397: 00
398: 00
399: 00
400: 65
401: 78
402: 65
403: 63
404: 75
405: 74
406: 61
407: 62
408: 6C
409: 65
410: 5F
411: 70
412: 61
413: 74
414: 68
415: 3D
416: 2E
417: 2F
418: 65
419: 78
420: 65
421: 63
422: 5F
423: 6D
424: 65
425: 6D
426: 6F
427: 72
428: 79
429: 74
430: 72
431: 61
432: 76
433: 65
434: 72
435: 73
436: 65
437: 00
438: 00
439: 00
440: 2E
441: 2F
442: 65
443: 78
444: 65
445: 63
446: 5F
447: 6D
448: 65
449: 6D
450: 6F
451: 72
452: 79
453: 74
454: 72
455: 61
456: 76
457: 65
458: 72
459: 73
460: 65
461: 00
462: 56
463: 49
464: 52
465: 54
466: 55
467: 41
468: 4C
469: 45
470: 4E
471: 56
472: 57
473: 52
474: 41
475: 50
476: 50
477: 45
478: 52
479: 5F
480: 53
481: 43
482: 52
483: 49
484: 50
485: 54
486: 3D
487: 2F
488: 75
489: 73
490: 72
491: 2F
492: 6C
493: 6F
494: 63
495: 61
496: 6C
497: 2F
498: 62
499: 69
500: 6E
501: 2F
502: 76
503: 69
504: 72
505: 74
506: 75
507: 61
508: 6C
509: 65
510: 6E
511: 76
512: 77
513: 72
514: 61
515: 70
516: 70
517: 65
518: 72
519: 2E
520: 73
521: 68
522: 00
523: 56
524: 49
525: 52
526: 54
527: 55
528: 41
529: 4C
530: 45
531: 4E
532: 56
533: 57
534: 52
535: 41
536: 50
537: 50
538: 45
539: 52
540: 5F
541: 50
542: 52
543: 4F
544: 4A
545: 45
546: 43
547: 54
548: 5F
549: 46
550: 49
551: 4C
552: 45
553: 4E
554: 41
555: 4D
556: 45
557: 3D
558: 2E
559: 70
560: 72
561: 6F
562: 6A
563: 65
564: 63
565: 74
566: 00
567: 54
568: 45
569: 52
570: 4D
571: 5F
572: 50
573: 52
574: 4F
575: 47
576: 52
577: 41
578: 4D
579: 3D
580: 41
581: 70
582: 70
583: 6C
584: 65
585: 5F
586: 54
587: 65
588: 72
589: 6D
590: 69
591: 6E
592: 61
593: 6C
594: 00
595: 54
596: 45
597: 52
598: 4D
599: 3D
600: 78
601: 74
602: 65
603: 72
604: 6D
605: 2D
606: 32
607: 35
608: 36
609: 63
610: 6F
611: 6C
612: 6F
613: 72
614: 00
615: 53
616: 48
617: 45
618: 4C
619: 4C
620: 3D
621: 2F
622: 62
623: 69
624: 6E
625: 2F
626: 62
627: 61
628: 73
629: 68
630: 00
631: 54
632: 4D
633: 50
634: 44
635: 49
636: 52
637: 3D
638: 2F
639: 76
640: 61
641: 72
642: 2F
643: 66
644: 6F
645: 6C
646: 64
647: 65
648: 72
649: 73
650: 2F
651: 74
652: 33
653: 2F
654: 6D
655: 39
656: 37
657: 73
658: 35
659: 33
660: 32
661: 35
662: 31
663: 32
664: 6C
665: 63
666: 36
667: 68
668: 66
669: 6A
670: 76
671: 30
672: 78
673: 6C
674: 76
675: 71
676: 68
677: 68
678: 30
679: 30
680: 30
681: 30
682: 67
683: 6E
684: 2F
685: 54
686: 2F
687: 00
688: 54
689: 45
690: 52
691: 4D
692: 5F
693: 50
694: 52
695: 4F
696: 47
697: 52
698: 41
699: 4D
700: 5F
701: 56
702: 45
703: 52
704: 53
705: 49
706: 4F
707: 4E
708: 3D
709: 34
710: 34
711: 30
712: 00
713: 54
714: 45
715: 52
716: 4D
717: 5F
718: 53
719: 45
720: 53
721: 53
722: 49
723: 4F
724: 4E
725: 5F
726: 49
727: 44
728: 3D
729: 42
730: 30
731: 30
732: 42
733: 39
734: 43
735: 37
736: 46
737: 2D
738: 32
739: 30
740: 38
741: 39
742: 2D
743: 34
744: 41
745: 38
746: 39
747: 2D
748: 41
749: 39
750: 46
751: 39
752: 2D
753: 30
754: 41
755: 42
756: 37
757: 43
758: 39
759: 45
760: 39
761: 37
762: 43
763: 38
764: 36
765: 00
766: 55
767: 53
768: 45
769: 52
770: 3D
771: 74
772: 79
773: 6C
774: 65
775: 72
776: 00
777: 53
778: 53
779: 48
780: 5F
781: 41
782: 55
783: 54
784: 48
785: 5F
786: 53
787: 4F
788: 43
789: 4B
790: 3D
791: 2F
792: 70
793: 72
794: 69
795: 76
796: 61
797: 74
798: 65
799: 2F
800: 74
801: 6D
802: 70
803: 2F
804: 63
805: 6F
806: 6D
807: 2E
808: 61
809: 70
810: 70
811: 6C
812: 65
813: 2E
814: 6C
815: 61
816: 75
817: 6E
818: 63
819: 68
820: 64
821: 2E
822: 62
823: 59
824: 53
825: 6F
826: 64
827: 70
828: 74
829: 50
830: 67
831: 43
832: 2F
833: 4C
834: 69
835: 73
836: 74
837: 65
838: 6E
839: 65
840: 72
841: 73
842: 00
843: 57
844: 4F
845: 52
846: 4B
847: 4F
848: 4E
849: 5F
850: 48
851: 4F
852: 4D
853: 45
854: 3D
855: 2F
856: 55
857: 73
858: 65
859: 72
860: 73
861: 2F
862: 74
863: 79
864: 6C
865: 65
866: 72
867: 2F
868: 2E
869: 76
870: 69
871: 72
872: 74
873: 75
874: 61
875: 6C
876: 65
877: 6E
878: 76
879: 73
880: 00
881: 56
882: 49
883: 52
884: 54
885: 55
886: 41
887: 4C
888: 45
889: 4E
890: 56
891: 57
892: 52
893: 41
894: 50
895: 50
896: 45
897: 52
898: 5F
899: 50
900: 59
901: 54
902: 48
903: 4F
904: 4E
905: 3D
906: 2F
907: 75
908: 73
909: 72
910: 2F
911: 6C
912: 6F
913: 63
914: 61
915: 6C
916: 2F
917: 62
918: 69
919: 6E
920: 2F
921: 70
922: 79
923: 74
924: 68
925: 6F
926: 6E
927: 33
928: 00
929: 50
930: 41
931: 54
932: 48
933: 3D
934: 2F
935: 4C
936: 69
937: 62
938: 72
939: 61
940: 72
941: 79
942: 2F
943: 46
944: 72
945: 61
946: 6D
947: 65
948: 77
949: 6F
950: 72
951: 6B
952: 73
953: 2F
954: 50
955: 79
956: 74
957: 68
958: 6F
959: 6E
960: 2E
961: 66
962: 72
963: 61
964: 6D
965: 65
966: 77
967: 6F
968: 72
969: 6B
970: 2F
971: 56
972: 65
973: 72
974: 73
975: 69
976: 6F
977: 6E
978: 73
979: 2F
980: 33
981: 2E
982: 37
983: 2F
984: 62
985: 69
986: 6E
987: 3A
988: 2F
989: 75
990: 73
991: 72
992: 2F
993: 6C
994: 6F
995: 63
996: 61
997: 6C
998: 2F
999: 62
1000: 69
1001: 6E
1002: 3A
1003: 2F
1004: 6F
1005: 70
1006: 74
1007: 2F
1008: 6C
1009: 6F
1010: 63
1011: 61
1012: 6C
1013: 2F
1014: 62
1015: 69
1016: 6E
1017: 3A
1018: 2F
1019: 6F
1020: 70
1021: 74
1022: 2F
1023: 6C
1024: 6F
1025: 63
1026: 61
1027: 6C
1028: 2F
1029: 73
1030: 62
1031: 69
1032: 6E
1033: 3A
1034: 2F
1035: 4C
1036: 69
1037: 62
1038: 72
1039: 61
1040: 72
1041: 79
1042: 2F
1043: 46
1044: 72
1045: 61
1046: 6D
1047: 65
1048: 77
1049: 6F
1050: 72
1051: 6B
1052: 73
1053: 2F
1054: 50
1055: 79
1056: 74
1057: 68
1058: 6F
1059: 6E
1060: 2E
1061: 66
1062: 72
1063: 61
1064: 6D
1065: 65
1066: 77
1067: 6F
1068: 72
1069: 6B
1070: 2F
1071: 56
1072: 65
1073: 72
1074: 73
1075: 69
1076: 6F
1077: 6E
1078: 73
1079: 2F
1080: 33
1081: 2E
1082: 37
1083: 2F
1084: 62
1085: 69
1086: 6E
1087: 3A
1088: 2F
1089: 75
1090: 73
1091: 72
1092: 2F
1093: 6C
1094: 6F
1095: 63
1096: 61
1097: 6C
1098: 2F
1099: 62
1100: 69
1101: 6E
1102: 3A
1103: 2F
1104: 75
1105: 73
1106: 72
1107: 2F
1108: 62
1109: 69
1110: 6E
1111: 3A
1112: 2F
1113: 62
1114: 69
1115: 6E
1116: 3A
1117: 2F
1118: 75
1119: 73
1120: 72
1121: 2F
1122: 73
1123: 62
1124: 69
1125: 6E
1126: 3A
1127: 2F
1128: 73
1129: 62
1130: 69
1131: 6E
1132: 3A
1133: 2F
1134: 4C
1135: 69
1136: 62
1137: 72
1138: 61
1139: 72
1140: 79
1141: 2F
1142: 54
1143: 65
1144: 58
1145: 2F
1146: 74
1147: 65
1148: 78
1149: 62
1150: 69
1151: 6E
1152: 3A
1153: 2F
1154: 4C
1155: 69
1156: 62
1157: 72
1158: 61
1159: 72
1160: 79
1161: 2F
1162: 41
1163: 70
1164: 70
1165: 6C
1166: 65
1167: 2F
1168: 75
1169: 73
1170: 72
1171: 2F
1172: 62
1173: 69
1174: 6E
1175: 3A
1176: 2F
1177: 4C
1178: 69
1179: 62
1180: 72
1181: 61
1182: 72
1183: 79
1184: 2F
1185: 46
1186: 72
1187: 61
1188: 6D
1189: 65
1190: 77
1191: 6F
1192: 72
1193: 6B
1194: 73
1195: 2F
1196: 4D
1197: 6F
1198: 6E
1199: 6F
1200: 2E
1201: 66
1202: 72
1203: 61
1204: 6D
1205: 65
1206: 77
1207: 6F
1208: 72
1209: 6B
1210: 2F
1211: 56
1212: 65
1213: 72
1214: 73
1215: 69
1216: 6F
1217: 6E
1218: 73
1219: 2F
1220: 43
1221: 75
1222: 72
1223: 72
1224: 65
1225: 6E
1226: 74
1227: 2F
1228: 43
1229: 6F
1230: 6D
1231: 6D
1232: 61
1233: 6E
1234: 64
1235: 73
1236: 00
1237: 56
1238: 49
1239: 52
1240: 54
1241: 55
1242: 41
1243: 4C
1244: 45
1245: 4E
1246: 56
1247: 57
1248: 52
1249: 41
1250: 50
1251: 50
1252: 45
1253: 52
1254: 5F
1255: 48
1256: 4F
1257: 4F
1258: 4B
1259: 5F
1260: 44
1261: 49
1262: 52
1263: 3D
1264: 2F
1265: 55
1266: 73
1267: 65
1268: 72
1269: 73
1270: 2F
1271: 74
1272: 79
1273: 6C
1274: 65
1275: 72
1276: 2F
1277: 2E
1278: 76
1279: 69
1280: 72
1281: 74
1282: 75
1283: 61
1284: 6C
1285: 65
1286: 6E
1287: 76
1288: 73
1289: 00
1290: 4C
1291: 61
1292: 75
1293: 6E
1294: 63
1295: 68
1296: 49
1297: 6E
1298: 73
1299: 74
1300: 61
1301: 6E
1302: 63
1303: 65
1304: 49
1305: 44
1306: 3D
1307: 35
1308: 32
1309: 35
1310: 45
1311: 36
1312: 39
1313: 43
1314: 33
1315: 2D
1316: 44
1317: 42
1318: 38
1319: 35
1320: 2D
1321: 34
1322: 33
1323: 44
1324: 46
1325: 2D
1326: 38
1327: 42
1328: 42
1329: 38
1330: 2D
1331: 38
1332: 31
1333: 38
1334: 41
1335: 39
1336: 35
1337: 38
1338: 42
1339: 44
1340: 39
1341: 31
1342: 45
1343: 00
1344: 5F
1345: 5F
1346: 43
1347: 46
1348: 42
1349: 75
1350: 6E
1351: 64
1352: 6C
1353: 65
1354: 49
1355: 64
1356: 65
1357: 6E
1358: 74
1359: 69
1360: 66
1361: 69
1362: 65
1363: 72
1364: 3D
1365: 63
1366: 6F
1367: 6D
1368: 2E
1369: 61
1370: 70
1371: 70
1372: 6C
1373: 65
1374: 2E
1375: 54
1376: 65
1377: 72
1378: 6D
1379: 69
1380: 6E
1381: 61
1382: 6C
1383: 00
1384: 50
1385: 57
1386: 44
1387: 3D
1388: 2F
1389: 56
1390: 6F
1391: 6C
1392: 75
1393: 6D
1394: 65
1395: 73
1396: 2F
1397: 47
1398: 6F
1399: 6F
1400: 67
1401: 6C
1402: 65
1403: 44
1404: 72
1405: 69
1406: 76
1407: 65
1408: 2F
1409: 4D
1410: 79
1411: 20
1412: 44
1413: 72
1414: 69
1415: 76
1416: 65
1417: 2F
1418: 4A
1419: 75
1420: 6E
1421: 69
1422: 6F
1423: 72
1424: 20
1425: 59
1426: 65
1427: 61
1428: 72
1429: 2F
1430: 53
1431: 70
1432: 72
1433: 69
1434: 6E
1435: 67
1436: 2F
1437: 43
1438: 53
1439: 33
1440: 33
1441: 33
1442: 2F
1443: 70
1444: 72
1445: 6F
1446: 6A
1447: 65
1448: 63
1449: 74
1450: 31
1451: 00
1452: 4C
1453: 41
1454: 4E
1455: 47
1456: 3D
1457: 65
1458: 6E
1459: 5F
1460: 55
1461: 53
1462: 2E
1463: 55
1464: 54
1465: 46
1466: 2D
1467: 38
1468: 00
1469: 58
1470: 50
1471: 43
1472: 5F
1473: 46
1474: 4C
1475: 41
1476: 47
1477: 53
1478: 3D
1479: 30
1480: 78
1481: 30
1482: 00
1483: 58
1484: 50
1485: 43
1486: 5F
1487: 53
1488: 45
1489: 52
1490: 56
1491: 49
1492: 43
1493: 45
1494: 5F
1495: 4E
1496: 41
1497: 4D
1498: 45
1499: 3D
1500: 30
1501: 00
1502: 48
1503: 4F
1504: 4D
1505: 45
1506: 3D
1507: 2F
1508: 55
1509: 73
1510: 65
1511: 72
1512: 73
1513: 2F
1514: 74
1515: 79
1516: 6C
1517: 65
1518: 72
1519: 00
1520: 53
1521: 48
1522: 4C
1523: 56
1524: 4C
1525: 3D
1526: 31
1527: 00
1528: 4C
1529: 4F
1530: 47
1531: 4E
1532: 41
1533: 4D
1534: 45
1535: 3D
1536: 74
1537: 79
1538: 6C
1539: 65
1540: 72
1541: 00
1542: 56
1543: 49
1544: 52
1545: 54
1546: 55
1547: 41
1548: 4C
1549: 45
1550: 4E
1551: 56
1552: 57
1553: 52
1554: 41
1555: 50
1556: 50
1557: 45
1558: 52
1559: 5F
1560: 57
1561: 4F
1562: 52
1563: 4B
1564: 4F
1565: 4E
1566: 5F
1567: 43
1568: 44
1569: 3D
1570: 31
1571: 00
1572: 53
1573: 45
1574: 43
1575: 55
1576: 52
1577: 49
1578: 54
1579: 59
1580: 53
1581: 45
1582: 53
1583: 53
1584: 49
1585: 4F
1586: 4E
1587: 49
1588: 44
1589: 3D
1590: 31
1591: 38
1592: 36
1593: 61
1594: 61
1595: 00
1596: 5F
1597: 3D
1598: 2E
1599: 2F
1600: 65
1601: 78
1602: 65
1603: 63
1604: 5F
1605: 6D
1606: 65
1607: 6D
1608: 6F
1609: 72
1610: 79
1611: 74
1612: 72
1613: 61
1614: 76
1615: 65
1616: 72
1617: 73
1618: 65
1619: 00
1620: 00
1621: 00
1622: 00
1623: 00
1624: 00
1625: 00
1626: 00
1627: 00
1628: 00
1629: 00
1630: 00
1631: 00
1632: 00
1633: 00
1634: 00
1635: 00
1636: 00
1637: 00
1638: 00
1639: 00
1640: 00
1641: 00
1642: 00
1643: 00
1644: 00
1645: 00
1646: 00
1647: 00
1648: 00
1649: 00
1650: 00
1651: 00
1652: 00
1653: 00
1654: 00
1655: 00
1656: 00
1657: 00
1658: 00
1659: 00
1660: 00
1661: 00
1662: 00
1663: 00
1664: 00
1665: 00
1666: 00
1667: 00
1668: 00
1669: 00
1670: 00
1671: 00
1672: 00
1673: 00
1674: 00
1675: 00
1676: 00
1677: 00
1678: 00
1679: 00
1680: 00
1681: 00
1682: 00
1683: 00
1684: 00
1685: 00
1686: 00
1687: 00
1688: 00
1689: 00
1690: 00
1691: 00
1692: 00
1693: 00
1694: 00
1695: 00
1696: 00
1697: 00
1698: 00
1699: 00
1700: 00
1701: 00
1702: 00
1703: 00
1704: 00
1705: 00
1706: 00
1707: 00
1708: 00
1709: 00
1710: 00
1711: 00
1712: 00
1713: 00
1714: 00
1715: 00
1716: 00
1717: 00
1718: 00
1719: 00
1720: 00
1721: 00
1722: 00
1723: 00
1724: 00
1725: 00
1726: 70
1727: 74
1728: 72
1729: 5F
1730: 6D
1731: 75
1732: 6E
1733: 67
1734: 65
1735: 3D
1736: 00
1737: 00
1738: 00
1739: 00
1740: 00
1741: 00
1742: 00
1743: 00
1744: 00
1745: 00
1746: 00
1747: 00
1748: 00
1749: 00
1750: 00
1751: 00
1752: 00
1753: 00
1754: 00
1755: 6D
1756: 61
1757: 69
1758: 6E
1759: 5F
1760: 73
1761: 74
1762: 61
1763: 63
1764: 6B
1765: 3D
1766: 00
1767: 00
1768: 00
1769: 00
1770: 00
1771: 00
1772: 00
1773: 00
1774: 00
1775: 00
1776: 00
1777: 00
1778: 00
1779: 00
1780: 00
1781: 00
1782: 00
1783: 00
1784: 00
1785: 00
1786: 00
1787: 00
1788: 00
1789: 00
1790: 00
1791: 00
1792: 00
1793: 00
1794: 00
1795: 00
1796: 00
1797: 00
1798: 00
1799: 00
1800: 00
1801: 00
1802: 00
1803: 00
1804: 00
1805: 00
1806: 00
1807: 00
1808: 00
1809: 00
1810: 00
1811: 00
1812: 00
1813: 00
1814: 00
1815: 65
1816: 78
1817: 65
1818: 63
1819: 75
1820: 74
1821: 61
1822: 62
1823: 6C
1824: 65
1825: 5F
1826: 66
1827: 69
1828: 6C
1829: 65
1830: 3D
1831: 30
1832: 78
1833: 33
1834: 34
1835: 30
1836: 30
1837: 30
1838: 30
1839: 30
1840: 33
1841: 2C
1842: 30
1843: 78
1844: 31
1845: 32
1846: 38
1847: 62
1848: 00
1849: 64
1850: 79
1851: 6C
1852: 64
1853: 5F
1854: 66
1855: 69
1856: 6C
1857: 65
1858: 3D
1859: 30
1860: 78
1861: 31
1862: 61
1863: 30
1864: 31
1865: 30
1866: 30
1867: 30
1868: 30
1869: 30
1870: 34
1871: 2C
1872: 30
1873: 78
1874: 66
1875: 66
1876: 66
1877: 66
1878: 66
1879: 66
1880: 66
1881: 30
1882: 30
1883: 30
1884: 64
1885: 63
1886: 62
1887: 39
1888: 32
1889: 00
1890: 00
1891: 00
1892: 00
1893: 00
1894: 00
1895: 00
Segmentation fault: 11
```

The aspects of the output that we are interested in are the fact that **(a)** we get a segmentation fault: 11 at the end of the program when we let it run with no boundary and that **(b)** we can actually find the other variables that are declared in the program in the output. Take a look at indices 32-35:

```
32: 67
33: 45
34: 23
35: 01
```

We find here the four bits storing the `integer` that is declared on line `19` of `memorytraverse.c`. This result is machine-dependent, however, so if you are reading this and want to try it for yourself it is not guaranteed that the same phenomenon occurs.

##### Task 3:

Without calling `free`, the program rapidly begins to take up more and more memory. It can be seen that it will climb to the top of your machine's memory usage.

With `free` inside the loop, however, the program's memory usage remains static at 436KB until it is manually terminated.

##### Task 4:

Creating an executable from `structmemory.c` called `exec_structmemory`, run the command `./exec_structmemory` and find the following:

```
0: 49
1: 74
2: 61
3: 6C
4: 69
5: 61
6: 6E
7: 00
8: 00
9: 00
10: 00
11: 00
12: 00
13: 00
14: 00
15: 00
16: 00
17: 00
18: 00
19: 00
20: 00
21: 00
22: 00
23: 57
24: 08
25: 00
Size of CarlsenNakamura is 26
```

It is readily apparent that bytes 0-22 are allocated for the `char` array `CarlsenNakamura.opening`, byte `23` holds `57` which is "W" in hexadecimal -- so it is holding `CarlsenNakammura.side`. Lastly, we find that bytes `24` and `25` are holding `CarlsenNakamura.num_pawns`.

What is interesting is that **(a)** the `sizeof()` call returns `26`. Ying said in class that it snaps to even multiples of the largest data type; since it is a `short` in this case, everything is a multiple of 2. So there is a buffer to make sure that `sizeof()` is always even, but there aren't any gaps between the different variables of the struct.

##### Task 5:

Creating an executable from `strcpyexploration.c` called `exec_strcpyexploration`, run the command `./exec_strcpyexploration` and find the following:

```
Illegal instruction: 4
```

So, it looks like my compiler throws an illegal instruction error in the event that you try to copy a string that is slightly too long.

#### Part II: Exploration of Other Languages

##### Imperative / Object-Oriented Language: Ruby

Developed in the mid-1990s, Ruby was designed by its creator Yukihiro “Matz” Matsumoto as a combination of his favorite languages to "form a new language that balanced functional programming with imperative programming." One interesting aspect of Ruby is that everything (including primitive types such as numbers) is an object, and so everything can have instance variables and methods. Ruby, while positioning itself as a general-purpose language has many applications like data analysis, prototyping, and proof of concepts. However, it is most often used in web applications; the largest implementation of Ruby is Ruby on Rails, the development framework built with Ruby. Ruby is a compiled language just like how Java works. Ruby syntax itself is not immediately compiled down to native machine code; instead, it is compiled into a set of bytecode instructions that are interpreted by a virtual machine. Ruby is completely open source and always free to copy, modify, and distribute.

##### Functional / Logic Language: Haskell

Created in 1990, Haskell is a purely functional programming language with some interesting properties: its statically typed, it has type inference, its "lazy" (meaning functions don't evaluate their arguments, so chains of functions can be fused together easily), it has concurrency and there are tons of packages available. From the Huffington Post, "While Haskell is a general purpose language that can be used in any domain and use case, it is ideally suited for proprietary business logic and data analysis, fast prototyping and enhancing existing software environments with correct code, performance and scalability." It has a native code compiler that is cross-platform and open source; open source contribution to Haskell comes by way of packages.

##### Special Purpose Language: MySQL

From their website: "MySQL is the world's most popular open source database. With its proven performance, reliability and ease-of-use, MySQL has become the leading database choice for web-based applications, used by high profile web properties including Facebook, Twitter, YouTube, Yahoo! and many more." It's secure, scalable, and fast. MySQL is free and open-source software under the terms of the GNU General Public License, and is also available under a variety of proprietary licenses. MySQL was owned and sponsored by the Swedish company MySQL AB, which was bought by Oracle. MySQL was originally released on May 23rd, 1995. DBMS (database management systems) are slightly different in that the "compilation" is called "optimization" and an "execution plan" is sent to the database for, well, execution. The execution yields the result.

#### Extensions:

##### Rust

An imperative language, Rust is "blazingly fast and memory-efficient: with no runtime or garbage collector, it can power performance-critical services, run on embedded devices, and easily integrate with other languages." Developed very recently in 2010, Rust's type system supports a mechanism similar to type classes, called "traits," inspired directly by the Haskell language. Performance of idiomatic Rust is comparable to the performance of idiomatic C++. Developers are using Rust to create a wide range of new software applications, such as game engines, operating systems, file systems, browser components and simulation engines for virtual reality. Rust is an open-source and compiled systems programming language.

##### Go

Go is an open-source, statically typed, compiled programming language designed at Google and released in 2012. Go is syntactically similar to C, but with memory safety, garbage collection, structural typing, and CSP-style concurrency. Go is a robust system-level language used for programming across large-scale network servers and big distributed systems. It emerged as an alternative to C++ and Java for the app developers in the context of what Google needed for its network servers and distributed systems. There is a debate amongst programmers regarding Rust versus Go, and I intend to learn both this semester.

##### Shortest Program to Generate Bus Error

Creating an executable from `buserror.c` called `exec_buserror`, run the command `./exec_buserror` and find the following:

```
Bus error: 10
```

From [mmap documentation:](https://pubs.opengroup.org/onlinepubs/000095399/functions/mmap.html)

```
References within the address range starting at pa and continuing for len bytes
to whole pages following the end of an object shall result in delivery of a SIGBUS
signal.
```

Originally, I tried causing a bus error using a misaligned memory access, but this no longer works on x86 systems. Too smart!

##### Adding 1.0 to a Large Float

I expected that the floating point number that would not change under an addition of 1.0 had to be along the upper boundary of allowed float values in C, that is, it must be very large. According to Mozilla, the maximum value of a float in C is `3.402823466 * 1e38`. I tested this by adding a 1.0 to this value and sure enough, I got the same number back.

##### User-Inputted String Copy

Lastly, I decided to let the user input which string they want to the `strcopy` experiment.
