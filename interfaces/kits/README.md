# API Description<a name="EN-US_TOPIC_0000001120353442"></a>

-   [type\_define.h](#section1595216182453)
-   [model\_config.h](#section19261840125219)
-   [feature\_interpreter.h](#section7405193574410)
-   [model\_interpreter.h](#section18190171223412)

## type\_define.h<a name="section1595216182453"></a>

**type\_define.h**  defines the return codes involved in the DLLite-Micro component, from which you can learn the exceptions.

**Table  1**  Constants defined in type\_define

<a name="table7392152410175"></a>
<table><thead align="left"><tr id="row439382471716"><th class="cellrowborder" valign="top" width="33.333333333333336%" id="mcps1.2.4.1.1"><p id="p83937243171"><a name="p83937243171"></a><a name="p83937243171"></a>Constant</p>
</th>
<th class="cellrowborder" valign="top" width="26.222622262226224%" id="mcps1.2.4.1.2"><p id="p1739352415177"><a name="p1739352415177"></a><a name="p1739352415177"></a>Description</p>
</th>
<th class="cellrowborder" valign="top" width="40.44404440444045%" id="mcps1.2.4.1.3"><p id="p439332418178"><a name="p439332418178"></a><a name="p439332418178"></a>Constant Value</p>
</th>
</tr>
</thead>
<tbody><tr id="row639372418174"><td class="cellrowborder" valign="top" width="33.333333333333336%" headers="mcps1.2.4.1.1 "><p id="p2393024191719"><a name="p2393024191719"></a><a name="p2393024191719"></a>ReturnCode</p>
</td>
<td class="cellrowborder" valign="top" width="26.222622262226224%" headers="mcps1.2.4.1.2 "><p id="p14393132451714"><a name="p14393132451714"></a><a name="p14393132451714"></a>Return value of the API running result</p>
</td>
<td class="cellrowborder" valign="top" width="40.44404440444045%" headers="mcps1.2.4.1.3 "><p id="p177161035172717"><a name="p177161035172717"></a><a name="p177161035172717"></a><strong id="b187471454143115"><a name="b187471454143115"></a><a name="b187471454143115"></a>SUCCESS</strong>: The operation result is successful.</p>
<p id="p3716193518271"><a name="p3716193518271"></a><a name="p3716193518271"></a><strong id="b4622155873112"><a name="b4622155873112"></a><a name="b4622155873112"></a>UNKNOWN</strong>: An unknown error occurs.</p>
<p id="p258019487200"><a name="p258019487200"></a><a name="p258019487200"></a><strong id="b12658935326"><a name="b12658935326"></a><a name="b12658935326"></a>INVALID_PARAM</strong>: The parameter is incorrect.</p>
<p id="p145805487201"><a name="p145805487201"></a><a name="p145805487201"></a><strong id="b18944101018499"><a name="b18944101018499"></a><a name="b18944101018499"></a>INVALID_POINTER</strong>: The pointer is null.</p>
<p id="p0580174822015"><a name="p0580174822015"></a><a name="p0580174822015"></a><strong id="b1315914571398"><a name="b1315914571398"></a><a name="b1315914571398"></a>REGISTER_REPEATED</strong>: The registration is repeated.</p>
<p id="p15580164818201"><a name="p15580164818201"></a><a name="p15580164818201"></a><strong id="b17516432405"><a name="b17516432405"></a><a name="b17516432405"></a>REGISTER_EXCEED_NUM_LIMIT</strong>: The number of feature registrations exceeds the upper limit.</p>
<p id="p758016480208"><a name="p758016480208"></a><a name="p758016480208"></a><strong id="b1636187194018"><a name="b1636187194018"></a><a name="b1636187194018"></a>UNREGISTER_WITH_TASK</strong>: The task is not unregistered.</p>
<p id="p1358054812015"><a name="p1358054812015"></a><a name="p1358054812015"></a><strong id="b42059109401"><a name="b42059109401"></a><a name="b42059109401"></a>DESTROY_WITH_TASK</strong>: A task is still running when an inference instance of a model is being destroyed, and resources cannot be released.</p>
<p id="p1471619359273"><a name="p1471619359273"></a><a name="p1471619359273"></a><strong id="b2246101614018"><a name="b2246101614018"></a><a name="b2246101614018"></a>LOAD_EXCEED_NUM_LIMIT</strong>: The number of loading attempts exceeds the upper limit.</p>
<p id="p371619357278"><a name="p371619357278"></a><a name="p371619357278"></a><strong id="b1440052117401"><a name="b1440052117401"></a><a name="b1440052117401"></a>LOAD_EXCEED_MEM_LIMIT</strong>: The number of loading attempts exceeds the memory limit.</p>
<p id="p14716133522711"><a name="p14716133522711"></a><a name="p14716133522711"></a><strong id="b88411525114016"><a name="b88411525114016"></a><a name="b88411525114016"></a>LOAD_REPEATED</strong>: The loading is repeated.</p>
<p id="p1571683572717"><a name="p1571683572717"></a><a name="p1571683572717"></a><strong id="b53339317407"><a name="b53339317407"></a><a name="b53339317407"></a>LOAD_NOT_EXECUTED</strong>: A loading error occurs.</p>
<p id="p177161935152711"><a name="p177161935152711"></a><a name="p177161935152711"></a><strong id="b18967163874011"><a name="b18967163874011"></a><a name="b18967163874011"></a>UNLOAD_MODEL_NOT_EXIST</strong>: The model to be unloaded does not exist.</p>
<p id="p1571633516272"><a name="p1571633516272"></a><a name="p1571633516272"></a><strong id="b8839174619403"><a name="b8839174619403"></a><a name="b8839174619403"></a>UNLOAD_MODEL_WITH_TASK</strong>: A model under inference is unloaded.</p>
<p id="p971643514277"><a name="p971643514277"></a><a name="p971643514277"></a><strong id="b1879885019400"><a name="b1879885019400"></a><a name="b1879885019400"></a>UNLOAD_REPEATED</strong>: The model is unloaded repeatedly.</p>
<p id="p1871614357275"><a name="p1871614357275"></a><a name="p1871614357275"></a><strong id="b12244185418401"><a name="b12244185418401"></a><a name="b12244185418401"></a>UNLOAD_HAS_EXECUTED</strong>: Model unloading has been executed.</p>
<p id="p107161635162714"><a name="p107161635162714"></a><a name="p107161635162714"></a><strong id="b574712579476"><a name="b574712579476"></a><a name="b574712579476"></a>INVOKE_NOT_EXISTED_MODEL</strong>: The inference model does not exist.</p>
<p id="p6716153522710"><a name="p6716153522710"></a><a name="p6716153522710"></a><strong id="b531414615485"><a name="b531414615485"></a><a name="b531414615485"></a>INVOKE_TENSOR_NOT_MATCH</strong>: The input tensor does not meet the model requirements.</p>
<p id="p1071653516276"><a name="p1071653516276"></a><a name="p1071653516276"></a><strong id="b1936323174913"><a name="b1936323174913"></a><a name="b1936323174913"></a>UNSUPPORTED_API</strong>: The API is not supported by the current version.</p>
<p id="p1071619509512"><a name="p1071619509512"></a><a name="p1071619509512"></a><strong id="b137637282495"><a name="b137637282495"></a><a name="b137637282495"></a>SERVER_BINDER_NOT_INIT</strong>: The task scheduling service binder is not initialized. (The return value is reserved for future use.)</p>
<p id="p177162035182719"><a name="p177162035182719"></a><a name="p177162035182719"></a><strong id="b3795631174914"><a name="b3795631174914"></a><a name="b3795631174914"></a>EMPTY_RESOURCE</strong>: There are empty resources.</p>
<p id="p671663518278"><a name="p671663518278"></a><a name="p671663518278"></a><strong id="b277013537522"><a name="b277013537522"></a><a name="b277013537522"></a>INVALID_MODEL_FILE</strong>: The model file is incorrect.</p>
<p id="p771683510275"><a name="p771683510275"></a><a name="p771683510275"></a><strong id="b895296125313"><a name="b895296125313"></a><a name="b895296125313"></a>FAILED_TO_GET_RESOURCE</strong>: The attempt to obtain resources has failed.</p>
</td>
</tr>
</tbody>
</table>

## model\_config.h<a name="section19261840125219"></a>

**Table  2**  Structure defined in model\_config

<a name="table334812159422"></a>
<table><thead align="left"><tr id="row17348151544210"><th class="cellrowborder" valign="top" width="33.33333333333333%" id="mcps1.2.4.1.1"><p id="p11227153614317"><a name="p11227153614317"></a><a name="p11227153614317"></a>Structure</p>
</th>
<th class="cellrowborder" valign="top" width="33.33333333333333%" id="mcps1.2.4.1.2"><p id="p14227936104313"><a name="p14227936104313"></a><a name="p14227936104313"></a>Description</p>
</th>
<th class="cellrowborder" valign="top" width="33.33333333333333%" id="mcps1.2.4.1.3"><p id="p12271536114314"><a name="p12271536114314"></a><a name="p12271536114314"></a>Property</p>
</th>
</tr>
</thead>
<tbody><tr id="row172714554719"><td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.1 "><p id="p1228114512474"><a name="p1228114512474"></a><a name="p1228114512474"></a>IOTensor</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.2 "><p id="p102812459474"><a name="p102812459474"></a><a name="p102812459474"></a><strong id="b137565345412"><a name="b137565345412"></a><a name="b137565345412"></a>IOTensor</strong> is used to store the input and output data of the AI inference framework. DLLite-Micro receives the data input by users and transparently transmits the data as IOTensor data to the underlying inference framework for inference. The inference result will also be output as IOTensor data.</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.3 "><p id="p6522712481"><a name="p6522712481"></a><a name="p6522712481"></a><strong id="b1558244712541"><a name="b1558244712541"></a><a name="b1558244712541"></a>string name</strong>: tensor name</p>
<p id="p7522211485"><a name="p7522211485"></a><a name="p7522211485"></a><strong id="b496182719550"><a name="b496182719550"></a><a name="b496182719550"></a>TensorType type</strong>: tensor type</p>
<p id="p1152215124815"><a name="p1152215124815"></a><a name="p1152215124815"></a><strong id="b17646311550"><a name="b17646311550"></a><a name="b17646311550"></a>TensorLayout layout</strong>: tensor layout</p>
<p id="p19522141174819"><a name="p19522141174819"></a><a name="p19522141174819"></a><strong id="b833919575586"><a name="b833919575586"></a><a name="b833919575586"></a>std::vector&lt;size_t&gt; shape</strong>: tensor size on each dimension</p>
<p id="p1522131144818"><a name="p1522131144818"></a><a name="p1522131144818"></a><strong id="b159474148019"><a name="b159474148019"></a><a name="b159474148019"></a>std::pair&lt;void*, size_t&gt; buffer</strong>: &lt;data, size&gt;</p>
</td>
</tr>
</tbody>
</table>

**Table  3**  TensorType enumerated values

<a name="table972098154915"></a>
<table><thead align="left"><tr id="row197201082493"><th class="cellrowborder" valign="top" width="33.33333333333333%" id="mcps1.2.4.1.1"><p id="p177201587490"><a name="p177201587490"></a><a name="p177201587490"></a>Definition</p>
</th>
<th class="cellrowborder" valign="top" width="33.33333333333333%" id="mcps1.2.4.1.2"><p id="p107201483493"><a name="p107201483493"></a><a name="p107201483493"></a>Value</p>
</th>
<th class="cellrowborder" valign="top" width="33.33333333333333%" id="mcps1.2.4.1.3"><p id="p167201688493"><a name="p167201688493"></a><a name="p167201688493"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row157200817491"><td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.1 "><p id="p73921212135013"><a name="p73921212135013"></a><a name="p73921212135013"></a>UINT8</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.2 "><p id="p73921121509"><a name="p73921121509"></a><a name="p73921121509"></a>0</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.3 "><p id="p9392111219507"><a name="p9392111219507"></a><a name="p9392111219507"></a>8-bit unsigned integer</p>
</td>
</tr>
<tr id="row572111854918"><td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.1 "><p id="p107221642105013"><a name="p107221642105013"></a><a name="p107221642105013"></a>INT8</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.2 "><p id="p8722242125020"><a name="p8722242125020"></a><a name="p8722242125020"></a>1</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.3 "><p id="p19722104215500"><a name="p19722104215500"></a><a name="p19722104215500"></a>8-bit signed integer</p>
</td>
</tr>
<tr id="row972114854912"><td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.1 "><p id="p47221642185012"><a name="p47221642185012"></a><a name="p47221642185012"></a>INT16</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.2 "><p id="p1572284215500"><a name="p1572284215500"></a><a name="p1572284215500"></a>2</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.3 "><p id="p1172320426507"><a name="p1172320426507"></a><a name="p1172320426507"></a>16-bit signed integer</p>
</td>
</tr>
<tr id="row17212834910"><td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.1 "><p id="p16723134210507"><a name="p16723134210507"></a><a name="p16723134210507"></a>UINT32</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.2 "><p id="p9723142145016"><a name="p9723142145016"></a><a name="p9723142145016"></a>3</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.3 "><p id="p8723942165012"><a name="p8723942165012"></a><a name="p8723942165012"></a>32-bit unsigned integer</p>
</td>
</tr>
<tr id="row27212816495"><td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.1 "><p id="p97239423504"><a name="p97239423504"></a><a name="p97239423504"></a>INT32</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.2 "><p id="p177231942105015"><a name="p177231942105015"></a><a name="p177231942105015"></a>4</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.3 "><p id="p167231942145013"><a name="p167231942145013"></a><a name="p167231942145013"></a>32-bit signed integer</p>
</td>
</tr>
<tr id="row127211287496"><td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.1 "><p id="p15723742195017"><a name="p15723742195017"></a><a name="p15723742195017"></a>FLOAT</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.2 "><p id="p177231342195010"><a name="p177231342195010"></a><a name="p177231342195010"></a>7</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.3 "><p id="p1172324218503"><a name="p1172324218503"></a><a name="p1172324218503"></a>Single-precision floating point</p>
</td>
</tr>
<tr id="row3721128104915"><td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.1 "><p id="p18221959175010"><a name="p18221959175010"></a><a name="p18221959175010"></a>FLOAT16</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.2 "><p id="p1622116598503"><a name="p1622116598503"></a><a name="p1622116598503"></a>8</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.3 "><p id="p11221185915015"><a name="p11221185915015"></a><a name="p11221185915015"></a>Half-precision floating point</p>
</td>
</tr>
<tr id="row164519182522"><td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.1 "><p id="p77061434155214"><a name="p77061434155214"></a><a name="p77061434155214"></a>INT64</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.2 "><p id="p7706173465219"><a name="p7706173465219"></a><a name="p7706173465219"></a>9</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.3 "><p id="p870713342522"><a name="p870713342522"></a><a name="p870713342522"></a>64-bit signed integer</p>
</td>
</tr>
<tr id="row18719821155214"><td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.1 "><p id="p1970723419521"><a name="p1970723419521"></a><a name="p1970723419521"></a>UINT16</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.2 "><p id="p1870753415216"><a name="p1870753415216"></a><a name="p1870753415216"></a>10</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.3 "><p id="p19707193419524"><a name="p19707193419524"></a><a name="p19707193419524"></a>16-bit unsigned integer</p>
</td>
</tr>
</tbody>
</table>

**Table  4**  TensorLayout enumerated values

<a name="table657025435313"></a>
<table><thead align="left"><tr id="row165703547531"><th class="cellrowborder" valign="top" width="33.33333333333333%" id="mcps1.2.4.1.1"><p id="p526619225410"><a name="p526619225410"></a><a name="p526619225410"></a>Definition</p>
</th>
<th class="cellrowborder" valign="top" width="33.33333333333333%" id="mcps1.2.4.1.2"><p id="p1426611255419"><a name="p1426611255419"></a><a name="p1426611255419"></a>Value</p>
</th>
<th class="cellrowborder" valign="top" width="33.33333333333333%" id="mcps1.2.4.1.3"><p id="p102673219546"><a name="p102673219546"></a><a name="p102673219546"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1957085415533"><td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.1 "><p id="p11570195455311"><a name="p11570195455311"></a><a name="p11570195455311"></a>NONE</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.2 "><p id="p13570145485315"><a name="p13570145485315"></a><a name="p13570145485315"></a>-1</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.3 "><p id="p10570754165311"><a name="p10570754165311"></a><a name="p10570754165311"></a>No data layout</p>
</td>
</tr>
<tr id="row557085415319"><td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.1 "><p id="p1457015455319"><a name="p1457015455319"></a><a name="p1457015455319"></a>NCHW</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.2 "><p id="p15701854175319"><a name="p15701854175319"></a><a name="p15701854175319"></a>0</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.3 "><p id="p457015425311"><a name="p457015425311"></a><a name="p457015425311"></a>NCHW data layout</p>
</td>
</tr>
<tr id="row2057035416538"><td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.1 "><p id="p155701654105317"><a name="p155701654105317"></a><a name="p155701654105317"></a>NHWC</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.2 "><p id="p8570454165311"><a name="p8570454165311"></a><a name="p8570454165311"></a>1</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.3 "><p id="p175701354105310"><a name="p175701354105310"></a><a name="p175701354105310"></a>NHWC data layout</p>
</td>
</tr>
<tr id="row1757015485313"><td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.1 "><p id="p257075425310"><a name="p257075425310"></a><a name="p257075425310"></a>HWKC</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.2 "><p id="p157055405318"><a name="p157055405318"></a><a name="p157055405318"></a>5</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.3 "><p id="p5571155415534"><a name="p5571155415534"></a><a name="p5571155415534"></a>HWKC data layout</p>
</td>
</tr>
<tr id="row1971023214"><td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.1 "><p id="p1481423512"><a name="p1481423512"></a><a name="p1481423512"></a>HWCK</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.2 "><p id="p98112318112"><a name="p98112318112"></a><a name="p98112318112"></a>6</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.3 "><p id="p18811231419"><a name="p18811231419"></a><a name="p18811231419"></a>HWCK data layout</p>
</td>
</tr>
<tr id="row145711554125314"><td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.1 "><p id="p4571205475318"><a name="p4571205475318"></a><a name="p4571205475318"></a>KCHW</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.2 "><p id="p857113541536"><a name="p857113541536"></a><a name="p857113541536"></a>7</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.3 "><p id="p37941473510"><a name="p37941473510"></a><a name="p37941473510"></a>KCHW data layout</p>
</td>
</tr>
<tr id="row11571195418533"><td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.1 "><p id="p165712549536"><a name="p165712549536"></a><a name="p165712549536"></a>CKHW</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.2 "><p id="p1857195435314"><a name="p1857195435314"></a><a name="p1857195435314"></a>8</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.3 "><p id="p187947479518"><a name="p187947479518"></a><a name="p187947479518"></a>CKHW data layout</p>
</td>
</tr>
<tr id="row15712054145314"><td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.1 "><p id="p1857195413536"><a name="p1857195413536"></a><a name="p1857195413536"></a>KHWC</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.2 "><p id="p657105419539"><a name="p657105419539"></a><a name="p657105419539"></a>9</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.3 "><p id="p187949471159"><a name="p187949471159"></a><a name="p187949471159"></a>KHWC data layout</p>
</td>
</tr>
<tr id="row357115455315"><td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.1 "><p id="p8571954115314"><a name="p8571954115314"></a><a name="p8571954115314"></a>CHWK</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.2 "><p id="p1557195418533"><a name="p1557195418533"></a><a name="p1557195418533"></a>10</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.3 "><p id="p11794134719510"><a name="p11794134719510"></a><a name="p11794134719510"></a>CHWK data layout</p>
</td>
</tr>
<tr id="row105711154175318"><td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.1 "><p id="p1157115455319"><a name="p1157115455319"></a><a name="p1157115455319"></a>NC4HW4</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.2 "><p id="p11571135412539"><a name="p11571135412539"></a><a name="p11571135412539"></a>11</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.3 "><p id="p1079454717515"><a name="p1079454717515"></a><a name="p1079454717515"></a>NC4HW4 data layout</p>
</td>
</tr>
<tr id="row135712054175318"><td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.1 "><p id="p857113547538"><a name="p857113547538"></a><a name="p857113547538"></a>NCHWC8</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.2 "><p id="p19571054185315"><a name="p19571054185315"></a><a name="p19571054185315"></a>2</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.3 "><p id="p1794647552"><a name="p1794647552"></a><a name="p1794647552"></a>NCHWC8 data layout</p>
</td>
</tr>
<tr id="row657145419535"><td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.1 "><p id="p9571125425313"><a name="p9571125425313"></a><a name="p9571125425313"></a>ROW_MAJOR</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.2 "><p id="p45719543531"><a name="p45719543531"></a><a name="p45719543531"></a>3</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.3 "><p id="p187941479513"><a name="p187941479513"></a><a name="p187941479513"></a>Row-major layout</p>
</td>
</tr>
<tr id="row957110548539"><td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.1 "><p id="p257195418533"><a name="p257195418533"></a><a name="p257195418533"></a>LSTM_MTK</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.2 "><p id="p10572854155310"><a name="p10572854155310"></a><a name="p10572854155310"></a>4</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.3 "><p id="p12794124717519"><a name="p12794124717519"></a><a name="p12794124717519"></a>LSTM_MTK data layout</p>
</td>
</tr>
</tbody>
</table>

**Table  5**  InferFrameworkType enumerated values

<a name="table4323105618496"></a>
<table><thead align="left"><tr id="row1632375684919"><th class="cellrowborder" valign="top" width="33.33333333333333%" id="mcps1.2.4.1.1"><p id="p6754182512121"><a name="p6754182512121"></a><a name="p6754182512121"></a>Definition</p>
</th>
<th class="cellrowborder" valign="top" width="33.33333333333333%" id="mcps1.2.4.1.2"><p id="p14754152551214"><a name="p14754152551214"></a><a name="p14754152551214"></a>Value</p>
</th>
<th class="cellrowborder" valign="top" width="33.33333333333333%" id="mcps1.2.4.1.3"><p id="p47541625141215"><a name="p47541625141215"></a><a name="p47541625141215"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row182112454514"><td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.1 "><p id="p202111145195114"><a name="p202111145195114"></a><a name="p202111145195114"></a>INFER</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.2 "><p id="p192111545155114"><a name="p192111545155114"></a><a name="p192111545155114"></a>-1</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.3 "><p id="p1415144218410"><a name="p1415144218410"></a><a name="p1415144218410"></a>Unspecified basic inference framework</p>
</td>
</tr>
<tr id="row1731544877"><td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.1 "><p id="p14731144417717"><a name="p14731144417717"></a><a name="p14731144417717"></a>MINDSPORE</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.2 "><p id="p07311844178"><a name="p07311844178"></a><a name="p07311844178"></a>0</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.3 "><p id="p973154412716"><a name="p973154412716"></a><a name="p973154412716"></a>MindSpore inference framework</p>
</td>
</tr>
</tbody>
</table>

**Table  6**  ModelConfig public variables

<a name="table1111012202717"></a>
<table><thead align="left"><tr id="row7110162014712"><th class="cellrowborder" valign="top" width="50%" id="mcps1.2.3.1.1"><p id="p1111052014711"><a name="p1111052014711"></a><a name="p1111052014711"></a>Variable</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.2.3.1.2"><p id="p101115205720"><a name="p101115205720"></a><a name="p101115205720"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1211132020710"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p811152013719"><a name="p811152013719"></a><a name="p811152013719"></a>std::string modelName_</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p1311162013712"><a name="p1311162013712"></a><a name="p1311162013712"></a>Model name.</p>
</td>
</tr>
<tr id="row347515161785"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p14752160813"><a name="p14752160813"></a><a name="p14752160813"></a>std::string modelPath_</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p1547516161281"><a name="p1547516161281"></a><a name="p1547516161281"></a>Path of the model structure file.</p>
</td>
</tr>
<tr id="row4444181815815"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p20444171811816"><a name="p20444171811816"></a><a name="p20444171811816"></a>std::string weightPath_</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p1144411181082"><a name="p1144411181082"></a><a name="p1144411181082"></a>Path of the model weight file. If <strong id="b1080512169919"><a name="b1080512169919"></a><a name="b1080512169919"></a>weightSeparateFlag_</strong> is set to <strong id="b1054531918919"><a name="b1054531918919"></a><a name="b1054531918919"></a>true</strong>, a separate model weight file needs to be provided. If <strong id="b19275141592"><a name="b19275141592"></a><a name="b19275141592"></a>weightSeparateFlag_</strong> is set to <strong id="b143743451696"><a name="b143743451696"></a><a name="b143743451696"></a>false</strong>, the value of this variable can be left empty.</p>
</td>
</tr>
<tr id="row7352122018814"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p1635362013814"><a name="p1635362013814"></a><a name="p1635362013814"></a>bool weightSeparateFlag_</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p1735322016817"><a name="p1735322016817"></a><a name="p1735322016817"></a>Weight separation flag. The model structure and weight of DLLite-Micro are separated on the ARM32A platform but not on the ARM32M platform. The default value is <strong id="b95166885172925"><a name="b95166885172925"></a><a name="b95166885172925"></a>true</strong>, indicating that the model structure and weight are separated.</p>
</td>
</tr>
</tbody>
</table>

**Table  7**  ModelConfig class APIs

<a name="table115596115214"></a>
<table><thead align="left"><tr id="row1115515619529"><th class="cellrowborder" valign="top" width="33.900000000000006%" id="mcps1.2.4.1.1"><p id="p039207115320"><a name="p039207115320"></a><a name="p039207115320"></a>API</p>
</th>
<th class="cellrowborder" valign="top" width="32.440000000000005%" id="mcps1.2.4.1.2"><p id="p039137115318"><a name="p039137115318"></a><a name="p039137115318"></a>API Description</p>
</th>
<th class="cellrowborder" valign="top" width="33.660000000000004%" id="mcps1.2.4.1.3"><p id="p23957195315"><a name="p23957195315"></a><a name="p23957195315"></a>Parameter Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row141559612525"><td class="cellrowborder" valign="top" width="33.900000000000006%" headers="mcps1.2.4.1.1 "><p id="p7911534165312"><a name="p7911534165312"></a><a name="p7911534165312"></a>ReturnCode CheckModelConfig() const</p>
</td>
<td class="cellrowborder" valign="top" width="32.440000000000005%" headers="mcps1.2.4.1.2 "><p id="p1019015365316"><a name="p1019015365316"></a><a name="p1019015365316"></a>Checks the model configuration file.</p>
<p id="p16612190185515"><a name="p16612190185515"></a><a name="p16612190185515"></a>Return values:</p>
<p id="p55361167559"><a name="p55361167559"></a><a name="p55361167559"></a><strong id="b1996215771218"><a name="b1996215771218"></a><a name="b1996215771218"></a>SUCCESS</strong>: The model configuration file is correct and the check is successful.</p>
<p id="p1843473717554"><a name="p1843473717554"></a><a name="p1843473717554"></a><strong id="b181449119137"><a name="b181449119137"></a><a name="b181449119137"></a>INVALID_PARAM</strong>: The inference model parameter is invalid.</p>
<p id="p6467945175510"><a name="p6467945175510"></a><a name="p6467945175510"></a><strong id="b398815315130"><a name="b398815315130"></a><a name="b398815315130"></a>EMPTY_RESOURCE</strong>: The model configuration file is empty.</p>
<p id="p51597526559"><a name="p51597526559"></a><a name="p51597526559"></a><strong id="b1092112821312"><a name="b1092112821312"></a><a name="b1092112821312"></a>INVALID_MODEL_FILE</strong>: The model configuration file is invalid.</p>
</td>
<td class="cellrowborder" valign="top" width="33.660000000000004%" headers="mcps1.2.4.1.3 "><p id="p1524712398529"><a name="p1524712398529"></a><a name="p1524712398529"></a>N/A</p>
</td>
</tr>
</tbody>
</table>

## feature\_interpreter.h<a name="section7405193574410"></a>

**Table  8**  Structure defined by feature\_interpreter

<a name="table163712681117"></a>
<table><thead align="left"><tr id="row186371926131113"><th class="cellrowborder" valign="top" width="33.93%" id="mcps1.2.4.1.1"><p id="p46384267115"><a name="p46384267115"></a><a name="p46384267115"></a>Structure</p>
</th>
<th class="cellrowborder" valign="top" width="32.57%" id="mcps1.2.4.1.2"><p id="p10638726101115"><a name="p10638726101115"></a><a name="p10638726101115"></a>Description</p>
</th>
<th class="cellrowborder" valign="top" width="33.5%" id="mcps1.2.4.1.3"><p id="p17821155511148"><a name="p17821155511148"></a><a name="p17821155511148"></a>Property</p>
</th>
</tr>
</thead>
<tbody><tr id="row26381426151117"><td class="cellrowborder" valign="top" width="33.93%" headers="mcps1.2.4.1.1 "><p id="p1638182661112"><a name="p1638182661112"></a><a name="p1638182661112"></a>VersionInfo</p>
</td>
<td class="cellrowborder" valign="top" width="32.57%" headers="mcps1.2.4.1.2 "><p id="p3638122614112"><a name="p3638122614112"></a><a name="p3638122614112"></a>Version information</p>
</td>
<td class="cellrowborder" valign="top" width="33.5%" headers="mcps1.2.4.1.3 "><p id="p68751646131519"><a name="p68751646131519"></a><a name="p68751646131519"></a><strong id="b58971743111414"><a name="b58971743111414"></a><a name="b58971743111414"></a>string version</strong>: DLLite-Micro version number</p>
<p id="p20875046171512"><a name="p20875046171512"></a><a name="p20875046171512"></a><strong id="b20669648201414"><a name="b20669648201414"></a><a name="b20669648201414"></a>vector&lt;string&gt; frameworkInfos</strong>: inference framework list</p>
</td>
</tr>
<tr id="row066105141715"><td class="cellrowborder" valign="top" width="33.93%" headers="mcps1.2.4.1.1 "><p id="p14661151171"><a name="p14661151171"></a><a name="p14661151171"></a>FrameworkInfo</p>
</td>
<td class="cellrowborder" valign="top" width="32.57%" headers="mcps1.2.4.1.2 "><p id="p46605101710"><a name="p46605101710"></a><a name="p46605101710"></a>Framework information</p>
</td>
<td class="cellrowborder" valign="top" width="33.5%" headers="mcps1.2.4.1.3 "><p id="p1852318296422"><a name="p1852318296422"></a><a name="p1852318296422"></a><strong id="b6842152211152"><a name="b6842152211152"></a><a name="b6842152211152"></a>string version</strong>: inference framework version number</p>
<p id="p5523329184220"><a name="p5523329184220"></a><a name="p5523329184220"></a><strong id="b68674273156"><a name="b68674273156"></a><a name="b68674273156"></a>string option</strong>: reserved. If this field is not used, leave the value empty.</p>
</td>
</tr>
<tr id="row42591227220"><td class="cellrowborder" valign="top" width="33.93%" headers="mcps1.2.4.1.1 "><p id="p1125902215210"><a name="p1125902215210"></a><a name="p1125902215210"></a>FeatureConfig</p>
</td>
<td class="cellrowborder" valign="top" width="32.57%" headers="mcps1.2.4.1.2 "><p id="p526017226219"><a name="p526017226219"></a><a name="p526017226219"></a>Feature configuration information. The value of <strong id="b6814236151519"><a name="b6814236151519"></a><a name="b6814236151519"></a>featureName</strong> must be unique.</p>
</td>
<td class="cellrowborder" valign="top" width="33.5%" headers="mcps1.2.4.1.3 "><p id="p192602224219"><a name="p192602224219"></a><a name="p192602224219"></a><strong id="b941616407159"><a name="b941616407159"></a><a name="b941616407159"></a>string featureName</strong>: feature name (mandatory)</p>
</td>
</tr>
</tbody>
</table>

**Table  9**  FeatureInterpreter class APIs

<a name="table1746717205576"></a>
<table><thead align="left"><tr id="row646812010576"><th class="cellrowborder" valign="top" width="34%" id="mcps1.2.4.1.1"><p id="p187731595918"><a name="p187731595918"></a><a name="p187731595918"></a>API</p>
</th>
<th class="cellrowborder" valign="top" width="43%" id="mcps1.2.4.1.2"><p id="p1177375135917"><a name="p1177375135917"></a><a name="p1177375135917"></a>API Description</p>
</th>
<th class="cellrowborder" valign="top" width="23%" id="mcps1.2.4.1.3"><p id="p17731959592"><a name="p17731959592"></a><a name="p17731959592"></a>Parameter Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1452155711715"><td class="cellrowborder" valign="top" width="34%" headers="mcps1.2.4.1.1 "><p id="p1979843151814"><a name="p1979843151814"></a><a name="p1979843151814"></a>static ReturnCode <strong id="b2079843141813"><a name="b2079843141813"></a><a name="b2079843141813"></a>GetVersion</strong>(VersionInfo&amp; versionInfo)</p>
</td>
<td class="cellrowborder" valign="top" width="43%" headers="mcps1.2.4.1.2 "><p id="p5798836184"><a name="p5798836184"></a><a name="p5798836184"></a>Obtains version information. </p>
<p id="p0798153171817"><a name="p0798153171817"></a><a name="p0798153171817"></a>Return value:</p>
<p id="p127983381812"><a name="p127983381812"></a><a name="p127983381812"></a><strong id="b850820913224"><a name="b850820913224"></a><a name="b850820913224"></a>SUCCESS</strong>: The version information is obtained successfully.</p>
</td>
<td class="cellrowborder" valign="top" width="23%" headers="mcps1.2.4.1.3 "><p id="p17799136182"><a name="p17799136182"></a><a name="p17799136182"></a><strong id="b14506621171718"><a name="b14506621171718"></a><a name="b14506621171718"></a>VersionInfo&amp; versionInfo</strong>: version information</p>
</td>
</tr>
<tr id="row3344102513237"><td class="cellrowborder" valign="top" width="34%" headers="mcps1.2.4.1.1 "><p id="p33441425112311"><a name="p33441425112311"></a><a name="p33441425112311"></a>static std::vector&lt;std::string&gt;<strong id="b11541130142315"><a name="b11541130142315"></a><a name="b11541130142315"></a>GetFeatureNameList</strong>()</p>
</td>
<td class="cellrowborder" valign="top" width="43%" headers="mcps1.2.4.1.2 "><p id="p1934412517234"><a name="p1934412517234"></a><a name="p1934412517234"></a>Obtains the list of names of all registered feature instances.</p>
<p id="p1546417394235"><a name="p1546417394235"></a><a name="p1546417394235"></a>Return value: List of names of all registered feature instances, which is stored in <strong id="b13758171664116"><a name="b13758171664116"></a><a name="b13758171664116"></a>vector&lt;std::string&gt;</strong> in the registration sequence. The value of <strong id="b1638942184119"><a name="b1638942184119"></a><a name="b1638942184119"></a>featureName</strong> in <strong id="b4320353914"><a name="b4320353914"></a><a name="b4320353914"></a>vector</strong> must be unique.</p>
</td>
<td class="cellrowborder" valign="top" width="23%" headers="mcps1.2.4.1.3 "><p id="p8344182572313"><a name="p8344182572313"></a><a name="p8344182572313"></a>N/A</p>
</td>
</tr>
<tr id="row2026121672514"><td class="cellrowborder" valign="top" width="34%" headers="mcps1.2.4.1.1 "><p id="p13910175255"><a name="p13910175255"></a><a name="p13910175255"></a>static std::shared_ptr&lt;FeatureInterpreter&gt;</p>
<p id="p3941719251"><a name="p3941719251"></a><a name="p3941719251"></a><strong id="b282652352515"><a name="b282652352515"></a><a name="b282652352515"></a>GetFeatureInterpreterByFeatureName</strong>(const std::string &amp;featureName)</p>
</td>
<td class="cellrowborder" valign="top" width="43%" headers="mcps1.2.4.1.2 "><p id="p32631642515"><a name="p32631642515"></a><a name="p32631642515"></a>Obtains a feature instance based on the passed feature instance name.</p>
<p id="p1231904112519"><a name="p1231904112519"></a><a name="p1231904112519"></a>Return value: <strong id="b562681135015"><a name="b562681135015"></a><a name="b562681135015"></a>featureInterpreter</strong> instance, used for managing the model inference instance.</p>
<p id="p139090429130"><a name="p139090429130"></a><a name="p139090429130"></a><strong id="b7909124212139"><a name="b7909124212139"></a><a name="b7909124212139"></a>nullptr:</strong></p>
<p id="p16256912132612"><a name="p16256912132612"></a><a name="p16256912132612"></a><strong id="b5793331101810"><a name="b5793331101810"></a><a name="b5793331101810"></a>featureName</strong> is not in the feature instance list.</p>
</td>
<td class="cellrowborder" valign="top" width="23%" headers="mcps1.2.4.1.3 "><p id="p142651662517"><a name="p142651662517"></a><a name="p142651662517"></a><strong id="b118161812211"><a name="b118161812211"></a><a name="b118161812211"></a>const std::string &amp;featureName</strong>: name of the feature instance to be obtained</p>
</td>
</tr>
<tr id="row567415071811"><td class="cellrowborder" valign="top" width="34%" headers="mcps1.2.4.1.1 "><p id="p679983171818"><a name="p679983171818"></a><a name="p679983171818"></a>static ReturnCode <strong id="b1799143151814"><a name="b1799143151814"></a><a name="b1799143151814"></a>GetFrameworkInfo</strong>(const std::string &amp;frameworkName, FrameworkInfo&amp; frameworkInfo)</p>
</td>
<td class="cellrowborder" valign="top" width="43%" headers="mcps1.2.4.1.2 "><p id="p1379920312182"><a name="p1379920312182"></a><a name="p1379920312182"></a>Obtains framework information.</p>
<p id="p1279911331812"><a name="p1279911331812"></a><a name="p1279911331812"></a>Return values:</p>
<p id="p979920315184"><a name="p979920315184"></a><a name="p979920315184"></a><strong id="b65282143313"><a name="b65282143313"></a><a name="b65282143313"></a>SUCCESS</strong>: The framework information is successfully obtained.</p>
<p id="p16799934181"><a name="p16799934181"></a><a name="p16799934181"></a><strong id="b163241246337"><a name="b163241246337"></a><a name="b163241246337"></a>INVALID_PARAM</strong>: The framework information parameter is invalid.</p>
</td>
<td class="cellrowborder" valign="top" width="23%" headers="mcps1.2.4.1.3 "><p id="p197991535185"><a name="p197991535185"></a><a name="p197991535185"></a><strong id="b17620158153317"><a name="b17620158153317"></a><a name="b17620158153317"></a>const std::string &amp;frameworkName</strong>: name of the inference framework to be queried</p>
<p id="p11799183121818"><a name="p11799183121818"></a><a name="p11799183121818"></a><strong id="b42091340114015"><a name="b42091340114015"></a><a name="b42091340114015"></a>FrameworkInfo&amp; frameworkInfo</strong>: information about the queried inference framework </p>
</td>
</tr>
<tr id="row57941414102811"><td class="cellrowborder" valign="top" width="34%" headers="mcps1.2.4.1.1 "><p id="p988515155281"><a name="p988515155281"></a><a name="p988515155281"></a>static std::shared_ptr&lt;ModelInterpreter&gt;</p>
<p id="p888541514285"><a name="p888541514285"></a><a name="p888541514285"></a><strong id="b1924121842818"><a name="b1924121842818"></a><a name="b1924121842818"></a>GetModelInterpreterByModelName</strong>(const std::string &amp;modelName)</p>
</td>
<td class="cellrowborder" valign="top" width="43%" headers="mcps1.2.4.1.2 "><p id="p8794161422817"><a name="p8794161422817"></a><a name="p8794161422817"></a>Obtains the inference instance based on the passed inference instance name.</p>
<p id="p52978318287"><a name="p52978318287"></a><a name="p52978318287"></a>Return value: <strong id="b39954198507"><a name="b39954198507"></a><a name="b39954198507"></a>modelInterpreter</strong> instance.</p>
<p id="p10898651959"><a name="p10898651959"></a><a name="p10898651959"></a><strong id="b1897171810400"><a name="b1897171810400"></a><a name="b1897171810400"></a>nullptr</strong>:</p>
<p id="p174831223161319"><a name="p174831223161319"></a><a name="p174831223161319"></a><strong id="b1058195174520"><a name="b1058195174520"></a><a name="b1058195174520"></a>modelName</strong> is not in the inference instance list.</p>
</td>
<td class="cellrowborder" valign="top" width="23%" headers="mcps1.2.4.1.3 "><p id="p37941614112814"><a name="p37941614112814"></a><a name="p37941614112814"></a><strong id="b1866015563454"><a name="b1866015563454"></a><a name="b1866015563454"></a>const std::string &amp;modelName</strong>: name of a model inference instance</p>
</td>
</tr>
<tr id="row95899015272"><td class="cellrowborder" valign="top" width="34%" headers="mcps1.2.4.1.1 "><p id="p1158911016279"><a name="p1158911016279"></a><a name="p1158911016279"></a>static std::vector&lt;std::string&gt;<strong id="b141306614274"><a name="b141306614274"></a><a name="b141306614274"></a>GetModelNameList</strong>()</p>
</td>
<td class="cellrowborder" valign="top" width="43%" headers="mcps1.2.4.1.2 "><p id="p1958911002715"><a name="p1958911002715"></a><a name="p1958911002715"></a>Obtains the list of names of all created inference instances.</p>
<p id="p1656918214276"><a name="p1656918214276"></a><a name="p1656918214276"></a>Return value: List of model inference instance names, which is stored in <strong id="b4913123218505"><a name="b4913123218505"></a><a name="b4913123218505"></a>vector&lt;std::string&gt;</strong> in the registration sequence. The value of <strong id="b157645492509"><a name="b157645492509"></a><a name="b157645492509"></a>modelName</strong> in <strong id="b127865294545"><a name="b127865294545"></a><a name="b127865294545"></a>vector</strong> must be unique.</p>
</td>
<td class="cellrowborder" valign="top" width="23%" headers="mcps1.2.4.1.3 "><p id="p1558990192716"><a name="p1558990192716"></a><a name="p1558990192716"></a>N/A</p>
</td>
</tr>
<tr id="row746820204576"><td class="cellrowborder" valign="top" width="34%" headers="mcps1.2.4.1.1 "><p id="p1346872013573"><a name="p1346872013573"></a><a name="p1346872013573"></a>static std::shared_ptr&lt;FeatureInterpreter&gt; <strong id="b421821795919"><a name="b421821795919"></a><a name="b421821795919"></a>RegisterFeature</strong>(const FeatureConfig&amp; featureConfig)</p>
</td>
<td class="cellrowborder" valign="top" width="43%" headers="mcps1.2.4.1.2 "><p id="p1446818207575"><a name="p1446818207575"></a><a name="p1446818207575"></a>Registers feature information with the DLLite-Micro control plane, initializes the configuration, and sets <strong id="b1269161817475"><a name="b1269161817475"></a><a name="b1269161817475"></a>featureName</strong> (which must be unique). The instantiation management class used for subsequent calls is returned. featureInterpreter</p>
<p id="p10627534185910"><a name="p10627534185910"></a><a name="p10627534185910"></a>Return value: <strong id="b1421859155012"><a name="b1421859155012"></a><a name="b1421859155012"></a>featureInterpreter</strong> instance, used for managing the model inference instance.</p>
<p id="p183801451"><a name="p183801451"></a><a name="p183801451"></a><strong id="b95674514466"><a name="b95674514466"></a><a name="b95674514466"></a>nullptr</strong>:</p>
<a name="ol104881537415"></a><a name="ol104881537415"></a><ol id="ol104881537415"><li>The length of <strong id="b63821958174613"><a name="b63821958174613"></a><a name="b63821958174613"></a>featureName</strong> exceeds the upper limit (256 characters).</li><li>The number of registered features reaches the upper limit (8 for each process).</li><li><strong id="b1991011319528"><a name="b1991011319528"></a><a name="b1991011319528"></a>featureName</strong> has been registered.</li></ol>
</td>
<td class="cellrowborder" valign="top" width="23%" headers="mcps1.2.4.1.3 "><p id="p646862013578"><a name="p646862013578"></a><a name="p646862013578"></a><strong id="b196373815213"><a name="b196373815213"></a><a name="b196373815213"></a>const FeatureConfig&amp; featurConfig</strong>: application configuration information, including the feature name (<strong id="b1867515045214"><a name="b1867515045214"></a><a name="b1867515045214"></a>featureName</strong>)</p>
</td>
</tr>
<tr id="row16468152012576"><td class="cellrowborder" valign="top" width="34%" headers="mcps1.2.4.1.1 "><p id="p19468192010573"><a name="p19468192010573"></a><a name="p19468192010573"></a>static ReturnCode <strong id="b91878014416"><a name="b91878014416"></a><a name="b91878014416"></a>UnregisterFeature</strong>(std::shared_ptr&lt;FeatureInterpreter&gt; &amp;featureInterpreter)</p>
</td>
<td class="cellrowborder" valign="top" width="43%" headers="mcps1.2.4.1.2 "><p id="p646822018574"><a name="p646822018574"></a><a name="p646822018574"></a>Unregisters feature information from the DLLite-Micro control panel and releases related resources.</p>
<p id="p1665519231042"><a name="p1665519231042"></a><a name="p1665519231042"></a>Return values:</p>
<p id="p1297912331849"><a name="p1297912331849"></a><a name="p1297912331849"></a><strong id="b1688818292530"><a name="b1688818292530"></a><a name="b1688818292530"></a>SUCCESS</strong>: The feature information is successfully unregistered.</p>
<p id="p29791833342"><a name="p29791833342"></a><a name="p29791833342"></a><strong id="b191291637205318"><a name="b191291637205318"></a><a name="b191291637205318"></a>UNKNOWN</strong>: The number of feature instances is 0.</p>
<p id="p149791331442"><a name="p149791331442"></a><a name="p149791331442"></a><strong id="b7925240135317"><a name="b7925240135317"></a><a name="b7925240135317"></a>INVALID_POINTER</strong>: The featureInterpreter instantiation is invalid.</p>
<p id="p29790332419"><a name="p29790332419"></a><a name="p29790332419"></a><strong id="b17552124312534"><a name="b17552124312534"></a><a name="b17552124312534"></a>INVALID_PARAM</strong>: The feature instance is not in the list.</p>
</td>
<td class="cellrowborder" valign="top" width="23%" headers="mcps1.2.4.1.3 "><p id="p1746882075712"><a name="p1746882075712"></a><a name="p1746882075712"></a><strong id="b12477248165316"><a name="b12477248165316"></a><a name="b12477248165316"></a>std::shared_ptr&lt;FeatureInterpreter&gt; &amp;featureInterpreter</strong>: application inference management class obtained during registration</p>
</td>
</tr>
<tr id="row1042614501554"><td class="cellrowborder" valign="top" width="34%" headers="mcps1.2.4.1.1 "><p id="p1742665020513"><a name="p1742665020513"></a><a name="p1742665020513"></a>std::shared_ptr&lt;ModelInterpreter&gt; <strong id="b1017185115717"><a name="b1017185115717"></a><a name="b1017185115717"></a>CreateModelInterpreter</strong>(const ModelConfig &amp;modelConfig)</p>
</td>
<td class="cellrowborder" valign="top" width="43%" headers="mcps1.2.4.1.2 "><p id="p1342613507516"><a name="p1342613507516"></a><a name="p1342613507516"></a>Obtains the inference instance of a model. Multiple inference instances can be generated for the same model.</p>
<p id="p1435425510815"><a name="p1435425510815"></a><a name="p1435425510815"></a>Return value: <strong id="b10830114580"><a name="b10830114580"></a><a name="b10830114580"></a>modelInterpreter</strong> instance. If the value is <strong id="b15791331205513"><a name="b15791331205513"></a><a name="b15791331205513"></a>nullptr</strong>, the creation fails. Otherwise, the creation is successful. The methods such as <strong id="b19608181813579"><a name="b19608181813579"></a><a name="b19608181813579"></a>load</strong> and <strong id="b23201645718"><a name="b23201645718"></a><a name="b23201645718"></a>invoke</strong> can be called through the returned <strong id="b6596182645713"><a name="b6596182645713"></a><a name="b6596182645713"></a>ModelInterpreter</strong> pointer. For more details, see the subsequent APIs.</p>
<p id="p3435102131019"><a name="p3435102131019"></a><a name="p3435102131019"></a><strong id="b16414710115713"><a name="b16414710115713"></a><a name="b16414710115713"></a>nullptr</strong>:</p>
<a name="ol15435192111106"></a><a name="ol15435192111106"></a><ol id="ol15435192111106"><li>The length of <strong id="b34981253195811"><a name="b34981253195811"></a><a name="b34981253195811"></a>modelName</strong> exceeds the upper limit (256 characters).</li><li>The value of <strong id="b483772110599"><a name="b483772110599"></a><a name="b483772110599"></a>modelName</strong> is empty.</li><li>The length of <strong id="b869812718595"><a name="b869812718595"></a><a name="b869812718595"></a>modelPath</strong> reaches the maximum (256 characters).</li><li>The length of <strong id="b682216402593"><a name="b682216402593"></a><a name="b682216402593"></a>weightPath</strong> reaches the maximum (256 characters).</li><li>The model size exceeds 300 KB.</li><li>The model file is empty.</li><li>The number of created inference instances reaches the upper limit (16 for each feature instance).</li><li><strong id="b499012451724"><a name="b499012451724"></a><a name="b499012451724"></a>modelName</strong> has been used.</li></ol>
</td>
<td class="cellrowborder" valign="top" width="23%" headers="mcps1.2.4.1.3 "><p id="p8127162818910"><a name="p8127162818910"></a><a name="p8127162818910"></a><strong id="b3645546438"><a name="b3645546438"></a><a name="b3645546438"></a>const ModelConfig &amp;modelConfig</strong>: model configuration information</p>
</td>
</tr>
<tr id="row636964111113"><td class="cellrowborder" valign="top" width="34%" headers="mcps1.2.4.1.1 "><p id="p536918411112"><a name="p536918411112"></a><a name="p536918411112"></a>ReturnCode <strong id="b8485101616196"><a name="b8485101616196"></a><a name="b8485101616196"></a>DestroyModelInterpreter</strong> (std::shared_ptr&lt;ModelInterpreter&gt;&amp;  modelInterpreter)</p>
</td>
<td class="cellrowborder" valign="top" width="43%" headers="mcps1.2.4.1.2 "><p id="p33693401118"><a name="p33693401118"></a><a name="p33693401118"></a>Destroys the passed inference instance to release the corresponding resources.</p>
<p id="p1446863551910"><a name="p1446863551910"></a><a name="p1446863551910"></a>Return values:</p>
<p id="p43747383192"><a name="p43747383192"></a><a name="p43747383192"></a><strong id="b83818315411"><a name="b83818315411"></a><a name="b83818315411"></a>SUCCESS</strong>: The model inference instance is successfully destroyed.</p>
<p id="p637416381191"><a name="p637416381191"></a><a name="p637416381191"></a><strong id="b5212183318420"><a name="b5212183318420"></a><a name="b5212183318420"></a>INVALID_PARAM</strong>:The inference model instance is invalid.</p>
</td>
<td class="cellrowborder" valign="top" width="23%" headers="mcps1.2.4.1.3 "><p id="p33691481120"><a name="p33691481120"></a><a name="p33691481120"></a><strong id="b71641358519"><a name="b71641358519"></a><a name="b71641358519"></a>std::shared_ptr&lt;ModelInterpreter&gt;&amp; modelInterpreter</strong>: inference instance to be destroyed</p>
</td>
</tr>
</tbody>
</table>

## model\_interpreter.h<a name="section18190171223412"></a>

**Table  10**  Constants defined in model\_interpreter

<a name="table176681414175113"></a>
<table><thead align="left"><tr id="row66681914105120"><th class="cellrowborder" valign="top" width="34.07340734073407%" id="mcps1.2.4.1.1"><p id="p4668214105117"><a name="p4668214105117"></a><a name="p4668214105117"></a>Constant</p>
</th>
<th class="cellrowborder" valign="top" width="32.59325932593259%" id="mcps1.2.4.1.2"><p id="p136680144514"><a name="p136680144514"></a><a name="p136680144514"></a>Description</p>
</th>
<th class="cellrowborder" valign="top" width="33.33333333333333%" id="mcps1.2.4.1.3"><p id="p18668121412516"><a name="p18668121412516"></a><a name="p18668121412516"></a>Constant Value</p>
</th>
</tr>
</thead>
<tbody><tr id="row36681914175116"><td class="cellrowborder" valign="top" width="34.07340734073407%" headers="mcps1.2.4.1.1 "><p id="p146692140519"><a name="p146692140519"></a><a name="p146692140519"></a>IOFlag</p>
</td>
<td class="cellrowborder" valign="top" width="32.59325932593259%" headers="mcps1.2.4.1.2 "><p id="p176691414135116"><a name="p176691414135116"></a><a name="p176691414135116"></a>Enumerated value of the I/O flag</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.3 "><p id="p19368754724"><a name="p19368754724"></a><a name="p19368754724"></a><strong id="b1687435721617"><a name="b1687435721617"></a><a name="b1687435721617"></a>INPUT</strong></p>
<p id="p1236815541624"><a name="p1236815541624"></a><a name="p1236815541624"></a><strong id="b52901315173"><a name="b52901315173"></a><a name="b52901315173"></a>OUTPUT</strong></p>
</td>
</tr>
</tbody>
</table>

**Table  11**  ModelInterpreter class APIs

<a name="table1584211619315"></a>
<table><thead align="left"><tr id="row13842131619313"><th class="cellrowborder" valign="top" width="34%" id="mcps1.2.4.1.1"><p id="p116642302318"><a name="p116642302318"></a><a name="p116642302318"></a>API</p>
</th>
<th class="cellrowborder" valign="top" width="41%" id="mcps1.2.4.1.2"><p id="p1466453033119"><a name="p1466453033119"></a><a name="p1466453033119"></a>API Description</p>
</th>
<th class="cellrowborder" valign="top" width="25%" id="mcps1.2.4.1.3"><p id="p26649301319"><a name="p26649301319"></a><a name="p26649301319"></a>Parameter Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row10842191663117"><td class="cellrowborder" valign="top" width="34%" headers="mcps1.2.4.1.1 "><p id="p1248112581576"><a name="p1248112581576"></a><a name="p1248112581576"></a>ReturnCode <strong id="b1120953914583"><a name="b1120953914583"></a><a name="b1120953914583"></a>Load</strong>()</p>
</td>
<td class="cellrowborder" valign="top" width="41%" headers="mcps1.2.4.1.2 "><p id="p675210456582"><a name="p675210456582"></a><a name="p675210456582"></a>Loads a model. The lightweight framework is a model that uses only C language. The model is actually a <strong id="b198714410211"><a name="b198714410211"></a><a name="b198714410211"></a>.so</strong> library. Load the model dynamic library, create a session, and obtain the input and output tensors of the model.</p>
<p id="p208479017596"><a name="p208479017596"></a><a name="p208479017596"></a>Return values:</p>
<p id="p132491740594"><a name="p132491740594"></a><a name="p132491740594"></a><strong id="b14221561154"><a name="b14221561154"></a><a name="b14221561154"></a>SUCCESS</strong>: The model is successfully loaded.</p>
<p id="p1971949184710"><a name="p1971949184710"></a><a name="p1971949184710"></a><strong id="b158306615618"><a name="b158306615618"></a><a name="b158306615618"></a>LOAD_REPEATED</strong>: The model has been loaded.</p>
<p id="p111247102525"><a name="p111247102525"></a><a name="p111247102525"></a><strong id="b33381135811"><a name="b33381135811"></a><a name="b33381135811"></a>INVALID_POINTER</strong>: The pointer is null.</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.4.1.3 "><p id="p5842916163118"><a name="p5842916163118"></a><a name="p5842916163118"></a>N/A</p>
</td>
</tr>
<tr id="row084271618317"><td class="cellrowborder" valign="top" width="34%" headers="mcps1.2.4.1.1 "><p id="p2843216183112"><a name="p2843216183112"></a><a name="p2843216183112"></a>ReturnCode <strong id="b64771045125911"><a name="b64771045125911"></a><a name="b64771045125911"></a>Unload</strong>()</p>
</td>
<td class="cellrowborder" valign="top" width="41%" headers="mcps1.2.4.1.2 "><p id="p1284361619311"><a name="p1284361619311"></a><a name="p1284361619311"></a>Unloads a model and releases the input and output inference memory resources.</p>
<p id="p1316311535598"><a name="p1316311535598"></a><a name="p1316311535598"></a>Return values:</p>
<p id="p129131301009"><a name="p129131301009"></a><a name="p129131301009"></a><strong id="b5471911100"><a name="b5471911100"></a><a name="b5471911100"></a>SUCCESS</strong>: The model is successfully unloaded.</p>
<p id="p1473017605510"><a name="p1473017605510"></a><a name="p1473017605510"></a><strong id="b181610123108"><a name="b181610123108"></a><a name="b181610123108"></a>UNLOAD_REPEATED</strong>: The model has been unloaded.</p>
<p id="p617194017555"><a name="p617194017555"></a><a name="p617194017555"></a><strong id="b568561411017"><a name="b568561411017"></a><a name="b568561411017"></a>INVALID_POINTER</strong>: The pointer is null.</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.4.1.3 "><p id="p784371613112"><a name="p784371613112"></a><a name="p784371613112"></a>N/A</p>
</td>
</tr>
<tr id="row10843171693117"><td class="cellrowborder" valign="top" width="34%" headers="mcps1.2.4.1.1 "><p id="p484381612319"><a name="p484381612319"></a><a name="p484381612319"></a>ReturnCode <strong id="b6248132109"><a name="b6248132109"></a><a name="b6248132109"></a>CreateTensors</strong>(std::vector&lt;IOTensor&gt;&amp; tensors, IOFlag flag)</p>
</td>
<td class="cellrowborder" valign="top" width="41%" headers="mcps1.2.4.1.2 "><p id="p1984316164315"><a name="p1984316164315"></a><a name="p1984316164315"></a>Creates tensors and allocates memory resources.</p>
<p id="p88547547012"><a name="p88547547012"></a><a name="p88547547012"></a>Return values:</p>
<p id="p6345658707"><a name="p6345658707"></a><a name="p6345658707"></a><strong id="b196371361768"><a name="b196371361768"></a><a name="b196371361768"></a>SUCCESS</strong>: Tensors are created and memory resources are allocated successfully.</p>
<p id="p14997810125920"><a name="p14997810125920"></a><a name="p14997810125920"></a><strong id="b149487171260"><a name="b149487171260"></a><a name="b149487171260"></a>LOAD_NOT_EXECUTED</strong>: The model is not loaded.</p>
<p id="p122151411119"><a name="p122151411119"></a><a name="p122151411119"></a><strong id="b3292711714"><a name="b3292711714"></a><a name="b3292711714"></a>INVALID_PARAM</strong>: The input/output flag is invalid.</p>
<p id="p156683210011"><a name="p156683210011"></a><a name="p156683210011"></a></p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.4.1.3 "><p id="p118431316203118"><a name="p118431316203118"></a><a name="p118431316203118"></a><strong id="b49561822070"><a name="b49561822070"></a><a name="b49561822070"></a>std::vector &lt;IOTensor&gt; &amp;tensors</strong>: tensors to be created</p>
<p id="p14634859811"><a name="p14634859811"></a><a name="p14634859811"></a><strong id="b1793371510814"><a name="b1793371510814"></a><a name="b1793371510814"></a>IOFlag flag</strong>: input/output flag</p>
<p id="p233435152120"><a name="p233435152120"></a><a name="p233435152120"></a>(This API is not supported in the current version. In the current version, <strong id="b9461134913"><a name="b9461134913"></a><a name="b9461134913"></a>ReturnCode::UNSUPPORTED_API</strong> is returned.)</p>
</td>
</tr>
<tr id="row78431216123110"><td class="cellrowborder" valign="top" width="34%" headers="mcps1.2.4.1.1 "><p id="p884313164313"><a name="p884313164313"></a><a name="p884313164313"></a>ReturnCode <strong id="b917114320310"><a name="b917114320310"></a><a name="b917114320310"></a>DestroyTensors</strong>(std::vector&lt;IOTensor&gt;&amp; tensors)</p>
</td>
<td class="cellrowborder" valign="top" width="41%" headers="mcps1.2.4.1.2 "><p id="p884321618314"><a name="p884321618314"></a><a name="p884321618314"></a>Releases the created tensors.</p>
<p id="p16504101717312"><a name="p16504101717312"></a><a name="p16504101717312"></a>Return values:</p>
<p id="p980610321636"><a name="p980610321636"></a><a name="p980610321636"></a><strong id="b962251441011"><a name="b962251441011"></a><a name="b962251441011"></a>SUCCESS</strong>: Tensors are successfully released.</p>
<p id="p17677190125"><a name="p17677190125"></a><a name="p17677190125"></a><strong id="b84611821171020"><a name="b84611821171020"></a><a name="b84611821171020"></a>LOAD_NOT_EXECUTED</strong>: The model is not loaded.</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.4.1.3 "><p id="p108431169313"><a name="p108431169313"></a><a name="p108431169313"></a><strong id="b9720327151013"><a name="b9720327151013"></a><a name="b9720327151013"></a>std::vector &lt;IOTensor&gt; &amp;tensors</strong>: tensors to be released</p>
<p id="p64001417124714"><a name="p64001417124714"></a><a name="p64001417124714"></a>(This API is not supported in the current version. In the current version, <strong id="b6452164620103"><a name="b6452164620103"></a><a name="b6452164620103"></a>ReturnCode::UNSUPPORTED_API</strong> is returned.)</p>
</td>
</tr>
<tr id="row1484310167319"><td class="cellrowborder" valign="top" width="34%" headers="mcps1.2.4.1.1 "><p id="p128437168319"><a name="p128437168319"></a><a name="p128437168319"></a>ReturnCode <strong id="b2624381146"><a name="b2624381146"></a><a name="b2624381146"></a>GetTensors</strong>(std::vector&lt;IOTensor&gt; &amp;tensors, IOFlag flag) const</p>
</td>
<td class="cellrowborder" valign="top" width="41%" headers="mcps1.2.4.1.2 "><p id="p78431165318"><a name="p78431165318"></a><a name="p78431165318"></a>Obtains tensor information.</p>
<p id="p143751058143"><a name="p143751058143"></a><a name="p143751058143"></a>Return values:</p>
<p id="p537510581542"><a name="p537510581542"></a><a name="p537510581542"></a><strong id="b91117580103"><a name="b91117580103"></a><a name="b91117580103"></a>SUCCESS</strong>: Tensor information is obtained successfully.</p>
<p id="p2010683465715"><a name="p2010683465715"></a><a name="p2010683465715"></a><strong id="b1418941151116"><a name="b1418941151116"></a><a name="b1418941151116"></a>INVALID_POINTER</strong>: The pointer is null.</p>
<p id="p1937511581843"><a name="p1937511581843"></a><a name="p1937511581843"></a><strong id="b1173416651111"><a name="b1173416651111"></a><a name="b1173416651111"></a>INVALID_PARAM</strong>: The input/output flag is invalid.</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.4.1.3 "><p id="p1986560141410"><a name="p1986560141410"></a><a name="p1986560141410"></a><strong id="b1577792571115"><a name="b1577792571115"></a><a name="b1577792571115"></a>std::vector &lt;IOTensor&gt; &amp;tensors</strong>: tensors to be created</p>
<p id="p108650012142"><a name="p108650012142"></a><a name="p108650012142"></a><strong id="b2095715271110"><a name="b2095715271110"></a><a name="b2095715271110"></a>IOFlag flag</strong>: input/output flag</p>
</td>
</tr>
<tr id="row1384301683115"><td class="cellrowborder" valign="top" width="34%" headers="mcps1.2.4.1.1 "><p id="p17843111643119"><a name="p17843111643119"></a><a name="p17843111643119"></a>ReturnCode <strong id="b103836197719"><a name="b103836197719"></a><a name="b103836197719"></a>Invoke</strong>(std::vector&lt;IOTensor&gt; &amp;inputs, std::vector&lt;IOTensor&gt; &amp;outputs) const</p>
</td>
<td class="cellrowborder" valign="top" width="41%" headers="mcps1.2.4.1.2 "><p id="p10843191610316"><a name="p10843191610316"></a><a name="p10843191610316"></a>Performs inference on <strong id="b516225271117"><a name="b516225271117"></a><a name="b516225271117"></a>inputs</strong> and get <strong id="b16407125151216"><a name="b16407125151216"></a><a name="b16407125151216"></a>outputs</strong>.</p>
<p id="p468731120812"><a name="p468731120812"></a><a name="p468731120812"></a>Return values:</p>
<p id="p1687311480"><a name="p1687311480"></a><a name="p1687311480"></a><strong id="b158427351972925"><a name="b158427351972925"></a><a name="b158427351972925"></a>SUCCESS</strong>: The inference is successful.</p>
<p id="p14673135233"><a name="p14673135233"></a><a name="p14673135233"></a><strong id="b1811914213511"><a name="b1811914213511"></a><a name="b1811914213511"></a>LOAD_NOT_EXECUTED</strong>: The model is not loaded.</p>
<p id="p18900981047"><a name="p18900981047"></a><a name="p18900981047"></a><strong id="b18352327131219"><a name="b18352327131219"></a><a name="b18352327131219"></a>INVALID_POINTER</strong>: The pointer is null.</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.4.1.3 "><p id="p174604372817"><a name="p174604372817"></a><a name="p174604372817"></a><strong id="b1756513334124"><a name="b1756513334124"></a><a name="b1756513334124"></a>std::vector&lt;IOTensor&gt; &amp;inputs</strong>: input tensor</p>
<p id="p17843316183118"><a name="p17843316183118"></a><a name="p17843316183118"></a><strong id="b10659164314124"><a name="b10659164314124"></a><a name="b10659164314124"></a>std::vector&lt;IOTensor&gt; &amp;outputs</strong>: output tensor</p>
</td>
</tr>
</tbody>
</table>

