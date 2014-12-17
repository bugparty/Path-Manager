.PHONY: clean All

All:
	@echo "----------构建项目：[PathManager - Debug ]----------"
	@$(MAKE) -f  "PathManager.mk" D:/wins/PathManager/include/main.h.gch && $(MAKE) -f  "PathManager.mk"
clean:
	@echo "----------清理项目：[PathManager - Debug ]----------"
	@$(MAKE) -f  "PathManager.mk" clean
